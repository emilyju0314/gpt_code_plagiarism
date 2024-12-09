YARPSoundDeviceDriver::YARPSoundDeviceDriver(void) : 
YARPDeviceDriver<YARPNullSemaphore, YARPSoundDeviceDriver>(SCMDNCmds)
{
	system_resources = (void *) new SoundResources;
	ACE_ASSERT (system_resources != NULL);

	/// for the IOCtl call. Here the mapping for the IOCtl should be included
	m_cmds[SCMDAcquireBuffer] = &YARPSoundDeviceDriver::acquireBuffer;
	m_cmds[SCMDReleaseBuffer] = &YARPSoundDeviceDriver::releaseBuffer;
	m_cmds[SCMDWaitNewFrame]  = &YARPSoundDeviceDriver::waitOnNewFrame;
	m_cmds[SCMDSetMute]       = &YARPSoundDeviceDriver::set_mute;
	m_cmds[SCMDSetVolume]     = &YARPSoundDeviceDriver::set_volume;
}