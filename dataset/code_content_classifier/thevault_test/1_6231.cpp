int 
SoundResources::_init (const SoundOpenParameters& params)
{
	//----------------------------------------------------------------------
	//  Initalize local parameters with the open params. It the open param
	//  is != 0 then the local param is updated if not the default value is
	//  used.
	//  Default configuration:
	//  16-bit, 44KHz, stereo
	//----------------------------------------------------------------------
	if (params.m_Channels      != 0) channels       = params.m_Channels;
	if (params.m_SamplesPerSec != 0) freqSample     = params.m_SamplesPerSec;
	if (params.m_BitsPerSample != 0) nBitsSample    = params.m_BitsPerSample;
	if (params.m_BufferLength  != 0) dwBufferLength = params.m_BufferLength;

	//----------------------------------------------------------------------
	//  Initialize the wave in
	//----------------------------------------------------------------------
	m_waveFormat.wFormatTag 	 = WAVE_FORMAT_PCM;
	m_waveFormat.nChannels 		 = channels;
	m_waveFormat.nSamplesPerSec  = freqSample;
	m_waveFormat.wBitsPerSample  = nBitsSample;
	m_waveFormat.nBlockAlign     = m_waveFormat.nChannels * (m_waveFormat.wBitsPerSample/8);
	m_waveFormat.nAvgBytesPerSec = m_waveFormat.nSamplesPerSec * m_waveFormat.nBlockAlign;
	m_waveFormat.cbSize          = 0;

	m_err = waveInOpen(&m_WaveInHandle, 
					   WAVE_MAPPER, 
					   &m_waveFormat, 
					   (DWORD)params.m_callbackthread_identifier, //Here I have to add the thread ID 
					   (DWORD)this, 
					   CALLBACK_THREAD);

	if (m_err != MMSYSERR_NOERROR) {
		printf("Can't open WAVE In Device! %d",m_err);
		return(-2);
	} 

	//----------------------------------------------------------------------
	//  Initialize Mixter
	//----------------------------------------------------------------------
	m_err = mixerOpen(&m_MixerHandle, 
					  (DWORD)m_WaveInHandle, 
					  0, 
					  0, 
					  MIXER_OBJECTF_HWAVEIN);

	if (m_err != MMSYSERR_NOERROR) {
		printf("yarpsounddriver: Device does not have mixer support! -- %08X\n", m_err);
	}

	//----------------------------------------------------------------------
	//  Print all the present lines in the audio interface
	//----------------------------------------------------------------------
	printf("yarpsounddriver: LINES PRESENT\n");
	_print_dst_lines();
	
	//----------------------------------------------------------------------
	// This device should have a WAVEIN destination line. Let's get its ID so
	// that we can determine what source lines are available to record from
	//----------------------------------------------------------------------
	m_mixerLine.cbStruct        = sizeof(MIXERLINE);
	m_mixerLine.dwComponentType = MIXERLINE_COMPONENTTYPE_DST_WAVEIN;

	m_err = mixerGetLineInfo((HMIXEROBJ)m_MixerHandle, 
							 &m_mixerLine, 
							 MIXER_GETLINEINFOF_COMPONENTTYPE);

	if (m_err != MMSYSERR_NOERROR) {
		printf("Device does not have a WAVE recording control! -- %08X\n", m_err);
	}
	
	m_numSrc = m_mixerLine.cConnections; // Get how many source lines are available from which to record. 
	m_err = _select_line(MIXERLINE_COMPONENTTYPE_SRC_LINE); //select default source line

	if (m_err == YARP_FAIL){ //Not line found, trying the auxiliary....
		m_err = _select_line(MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY);
	}

	if (m_err != YARP_OK)
		printf("yarpsounddriver: Atention Source line not found!!!\n");
		
	//----------------------------------------------------------------------
	// Initialize the local buffers 
	//----------------------------------------------------------------------
	_bmutex.Wait ();
	_rawBuffer = new unsigned char [dwBufferLength];
	ACE_ASSERT (_rawBuffer != NULL);
	_bmutex.Post ();

	return YARP_OK; 
}