int YARPEsdCanDeviceDriver::getControlMode (void *cmd)
{
    short value = 0;
	SingleAxisParameters *tmp = (SingleAxisParameters *) cmd;
	const int axis = tmp->axis;
	ACE_ASSERT (axis >= 0 && axis <= (ESD_MAX_CARDS-1)*2);

   	if (_readWord16 (CAN_GET_CONTROL_MODE, axis, value) != YARP_OK)
	{
		*((double *)tmp->parameters) = 0;
		return YARP_FAIL;
	}

	*((double *)tmp->parameters) = double(value); 
    return YARP_OK;
}