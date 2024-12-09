int YARPEsdCanDeviceDriver::velocityMove (void *cmd)
{
	/// prepare can message.
	EsdCanResources& r = RES(system_resources);
	double *tmp = (double *)cmd;
	int i;

	_mutex.Wait();
	r.startPacket();

	for (i = 0; i < r.getJoints(); i++)
	{
		if (ENABLED (i))
		{
			r.addMessage (CAN_VELOCITY_MOVE, i);
			const int j = r._writeMessages - 1;
			_ref_speeds[i] = tmp[i];
			*((short*)(r._writeBuffer[j].data+1)) = S_16(_ref_speeds[i]);	/// speed
			*((short*)(r._writeBuffer[j].data+3)) = S_16(_ref_accs[i]);		/// accel
			r._writeBuffer[j].len = 5;
		}
		else
		{
			_ref_speeds[i] = tmp[i];
		}
	}

	_writerequested = true;
	_noreply = true;

	_mutex.Post();

	_done.Wait();

	return YARP_OK;
}