int YARPEsdCanDeviceDriver::checkMotionDone (void *cmd)
{
	EsdCanResources& r = RES(system_resources);
	int i;
	short value;
	bool *out = (bool *) cmd;

	_mutex.Wait();
	r.startPacket();

	for (i = 0; i < r.getJoints(); i++)
	{
		if (ENABLED(i))
		{
			r.addMessage (CAN_MOTION_DONE, i);
		}
	}

	if (r._writeMessages < 1)
		return YARP_FAIL;

	_writerequested = true;
	_noreply = false;
	_mutex.Post();

	_done.Wait();

	if (r.getErrorStatus() != YARP_OK)
	{
		*out = false;
		return YARP_FAIL;
	}

	int j;
	for (i = 0, j = 0; i < r.getJoints(); i++)
	{
		if (ENABLED(i))
		{
			CMSG& m = r._replyBuffer[j];
			if (m.id != 0xffff)
			{
				value = *((short *)(m.data+1));
				if (!value)
				{
					*out = false;
					return YARP_OK;
				}
			}
			j++;
		}
	}

	*out = true;
	return YARP_OK;
}