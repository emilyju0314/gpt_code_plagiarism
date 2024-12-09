int 
YARPSoundDeviceDriver::waitOnNewFrame (void *cmd)
{
	SoundResources& d = RES(system_resources);
	d._new_frame.Wait ();

	return YARP_OK;
}