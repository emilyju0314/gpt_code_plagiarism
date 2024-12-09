int
SoundResources::_select_control(unsigned int control_type)
{
	//----------------------------------------------------------------------
	//  Fill the mixerLineControls structure
	//----------------------------------------------------------------------
	m_mixerLineControls.cbStruct      = sizeof(MIXERLINECONTROLS);
	m_mixerLineControls.dwLineID      = m_mixerLine.dwLineID;
	m_mixerLineControls.cControls     = 1;
	m_mixerLineControls.dwControlType = control_type;
	m_mixerLineControls.pamxctrl      = &m_mixerControlArray;
	m_mixerLineControls.cbmxctrl      = sizeof(MIXERCONTROL);

	m_err = mixerGetLineControls((HMIXEROBJ)m_MixerHandle, 
								 &m_mixerLineControls, 
								 MIXER_GETLINECONTROLSF_ONEBYTYPE);
	
	if (m_err != MMSYSERR_NOERROR) 
		printf("yarpsounddriver: %s has no %s control!\n", 
			   m_mixerLine.szName, 
			   m_mixerLineControls.pamxctrl->szName);
	
	return YARP_OK;
}