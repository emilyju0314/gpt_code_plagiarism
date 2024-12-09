int YARPEsdCanDeviceDriver::setDebugMessageFilter (void *cmd)
{
	_mutex.Wait();
	EsdCanResources& r = RES(system_resources);
	_filter = *(int *)cmd;
	_mutex.Post();

	return YARP_OK;
}