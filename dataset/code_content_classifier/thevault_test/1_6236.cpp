int 
YARPSoundDeviceDriver::acquireBuffer (void *buffer)
{
	SoundResources& d = RES(system_resources);
	d._bmutex.Wait ();
	(*(unsigned char **)buffer) = d._rawBuffer;

	return YARP_OK;
}