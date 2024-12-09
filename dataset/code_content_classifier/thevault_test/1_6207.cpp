int YARPEsdDeviceDriver::getBCastPosition (void *cmd)
{
	EsdResources& r = RES(system_resources);
	SingleAxisParameters *tmp = (SingleAxisParameters *) cmd;
	const int axis = tmp->axis;
	ACE_ASSERT (axis >= 0 && axis <= r.getJoints());

    _mutex.Wait();
	*((double *)tmp->parameters) = double(r._bcastRecvBuffer[axis]._position);
    _mutex.Post();

	return YARP_OK;
}