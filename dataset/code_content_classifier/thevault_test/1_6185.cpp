int 
SoundIdentificationProcessing::TruncateSoundToVector(
	const int length,
	YVector &vector
	) {
	try {
		LOCAL_TRACE("SoundIdentificationProcessing: Entering TruncateSoundToVector");
		double _dPositionDiferential = 0.0; /** The position increment/decrement.       */
		double _dAproxPosition       = 0.0; /** Aproximate new position.                */
		int    _iPosition            = 0;   /** The position in integer format.         */

		vector.Resize(length); 

		_dPositionDiferential = (double)numSamples/(double)length;

		int i;
		for( i = 0; i < length; i++){

			_dAproxPosition  = _dAproxPosition + _dPositionDiferential;
			_iPosition = GetInteger( _dAproxPosition );

			if ((_iPosition < numSamples) && (_iPosition >= 0))
				vector[i] = _pSoundData[_iPosition];
		}

		return YARP_OK;

	}
	catch (...) {
		 ACE_OS::fprintf(stdout,"SoundIdentificationProcessing: Exception TruncateSoundToVector\n");	 	 	  
		 return YARP_FAIL;
	}
}