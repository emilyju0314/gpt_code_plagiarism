int
YARPSoundDeviceDriver::releaseBuffer (void *cmd)
{
	SoundResources& d = RES(system_resources);
	d._canpost = true;
	d._bmutex.Post ();

	return YARP_OK;
}