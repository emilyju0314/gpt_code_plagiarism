int YARPEsdCanDeviceDriver::setPositions (void *cmd)
{
	EsdCanResources& r = RES(system_resources);
	double *tmp = (double *)cmd;
	int i;

	_mutex.Wait();
	r.startPacket();

	for (i = 0; i < r.getJoints (); i++)
	{
		if (ENABLED(i))
		{
			//SingleAxisParameters x;
			//x.axis = i;
			//x.parameters = tmp+i;	

			r.addMessage (CAN_POSITION_MOVE, i);
			const int j = r._writeMessages - 1;
			_ref_positions[i] = tmp[i];
			*((int*)(r._writeBuffer[j].data+1)) = S_32(_ref_positions[i]);		/// pos
			*((short*)(r._writeBuffer[j].data+5)) = S_16(_ref_speeds[i]);		/// speed
			r._writeBuffer[j].len = 7;
		}
		else
		{
			_ref_positions[i] = tmp[i];
		}
	}

	_writerequested = true;
	_noreply = true;
	
	_mutex.Post();

	/// syncing.
	_done.Wait();

	return YARP_OK;
}