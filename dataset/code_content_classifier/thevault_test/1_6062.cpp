int YARPEsdCanDeviceDriver::setSpeed (void *cmd)
{
	SingleAxisParameters *tmp = (SingleAxisParameters *) cmd;
	const int axis = tmp->axis;
	ACE_ASSERT (axis >= 0 && axis <= (ESD_MAX_CARDS-1)*2);
	
	_ref_speeds[axis] = *((double *)(tmp->parameters));
	//const short s = S_16(_ref_speeds[axis]);
	//return _writeWord16 (CAN_SET_DESIRED_VELOCITY, axis, s);
	return YARP_OK;
}