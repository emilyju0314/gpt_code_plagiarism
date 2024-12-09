int YARPEsdCanDeviceDriver::_readDWordArray (int msg, double *out)
{
	EsdCanResources& r = RES(system_resources);
	int i, value = 0;

	_mutex.Wait();
	r.startPacket();

	for (i = 0; i < r.getJoints(); i++)
	{
		if (ENABLED(i))
		{
			r.addMessage (msg, i);
		}
		else
			out[i] = 0;
	}

	if (r._writeMessages < 1)
	{
		_mutex.Post();
		return YARP_FAIL;
	}

	_writerequested = true;
	_noreply = false;
	_mutex.Post();

	_done.Wait();

	if (r.getErrorStatus() != YARP_OK)
	{
		memset (out, 0, sizeof(double) * r.getJoints());
		return YARP_FAIL;
	}

	int j;
	for (i = 0, j = 0; i < r.getJoints(); i++)
	{
		if (ENABLED(i))
		{
			CMSG& m = r._replyBuffer[j];
			if (m.id == 0xffff)
				out[i] = 0;
			else
				out[i] = *((int *)(m.data+1));
			j++;
		}
	}

	return YARP_OK;
}