int
SoundIdentificationProcessing::NormalizeSoundArray( const double Limit)
{
	try {
		LOCAL_TRACE("SoundIdentificationProcessing: Entering NormalizeSoundArray");
		int i;

		for( i=0; i<numSamples; i++){
			_pSoundData[i] = _pSoundData[i] / (double)Limit; 
		}
		return YARP_OK;
	}
	catch (...) {
		ACE_OS::fprintf(stdout,"SoundIdentificationProcessing: Exception NormalizeSoundArray\n");	 	 	  
		return YARP_FAIL;
	}
}