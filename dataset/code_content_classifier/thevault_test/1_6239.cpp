int 
YARPSoundDeviceDriver::set_volume(void *cmd)
{
	MIXERCONTROLDETAILS_UNSIGNED	value[2];
	MIXERCONTROLDETAILS				mixerControlDetails;
	MMRESULT						err;
	
	SoundResources& d = RES(system_resources);

	unsigned int * m_volume = (unsigned int *) cmd;

	/*
	 * Select the control type in the current line
	 */
	d._select_control(MIXERCONTROL_CONTROLTYPE_VOLUME);
	
	mixerControlDetails.cbStruct       = sizeof(MIXERCONTROLDETAILS);
	mixerControlDetails.dwControlID    = d.m_mixerControlArray.dwControlID;
	mixerControlDetails.cChannels      = 2;
	mixerControlDetails.cMultipleItems = 0;
	mixerControlDetails.paDetails      = &value[0];
	mixerControlDetails.cbDetails      = sizeof(MIXERCONTROLDETAILS_UNSIGNED);

	value[0].dwValue = value[1].dwValue = (*m_volume);

	err = mixerSetControlDetails((HMIXEROBJ)d.m_MixerHandle, 
								 &mixerControlDetails, 
								 MIXER_SETCONTROLDETAILSF_VALUE);
	
	if( err != MMSYSERR_NOERROR) printf("yarpsounddriver: Error #%d setting mute for %s!\n", err, d.m_mixerLine.szName);
	
	return YARP_OK;
}