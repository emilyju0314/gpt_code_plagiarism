int YARPEsdCanDeviceDriver::checkMotionDoneSingle (void *cmd)
{
    SingleAxisParameters *tmp = (SingleAxisParameters *) cmd;
	const int axis = tmp->axis;
	ACE_ASSERT (axis >= 0 && axis <= (ESD_MAX_CARDS-1)*2);
	
	short value;
	double *out = (double *)tmp->parameters;

    if (_readWord16 (CAN_MOTION_DONE, axis, value) == YARP_OK)
    {
        *out = double(value);
    }
    else
    {
        *out = 0;
        return YARP_FAIL;
    }

    return YARP_OK;
}