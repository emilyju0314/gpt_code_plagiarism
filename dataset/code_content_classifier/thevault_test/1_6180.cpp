SoundIdentificationProcessing::SoundIdentificationProcessing(const YARPString &iniFile, int outsize)
{
	YARPConfigFile file;
	char *root = GetYarpRoot();

	//----------------------------------------------------------------------
	//  Default sound parameters. These are calculated to have a stream of
	//  sound data each 40 miliseconds (the same that for the images)
	//----------------------------------------------------------------------
	_Channels      = 2;
	_SamplesPerSec = 44100;
	_BitsPerSample = 16;
	_iniFile       = iniFile;
	_outSize       = outsize;
	_sombufferlengthinsec = 10;
	_InputBufferLength    = 7056;

	//----------------------------------------------------------------------
	//  Initialization of the filter bank parameters, this should be added
	//  later to the initialization file
	//----------------------------------------------------------------------
	lowestFrequency      = 133.3333;
	linearFilters        = 13;
	linearSpacing        = 66.66666666;
	logFilters           = 27;
	logSpacing           = 1.0711703;
	cepstralCoefficients = 13;

	totalfilters = linearFilters + logFilters;

	filters_energy_vector.Resize(1,totalfilters);

	_path.append(root);
	//_path.append("/conf/babybot/"); 
	_path.append("/");
	_path.append(ConfigFilePath); 

	//----------------------------------------------------------------------
	//  Just recover from the configuration file the real sound parameters the user
	//  is using  
	//----------------------------------------------------------------------
	//file.set(_path, _iniFile);
	//file.get("[GENERAL]"   , "Channels"          , &_Channels             , 1);
	//file.get("[GENERAL]"   , "SamplesPerSec"     , &_SamplesPerSec        , 1);
	//file.get("[GENERAL]"   , "BitsPerSample"     , &_BitsPerSample        , 1);
	//file.get("[GENERAL]"   , "BufferLength"      , &_InputBufferLength    , 1);
	//file.get("[SOMBUFFER]" , "BufferLengthInSec" , &_sombufferlengthinsec , 1);

	switch( _Channels ) {
		case 1: 
			if ( _BitsPerSample == 16 )
				numSamples = _InputBufferLength/2; 
			else
				numSamples = _InputBufferLength;
			break;
		case 2:
			if ( _BitsPerSample == 16)
				numSamples = _InputBufferLength/4;
			else
				numSamples = _InputBufferLength/2;
			break;
	}
    numFreqSamples = numSamples/2 + 1;

	counter = 0; 

	ComputeIDCMatrix (
		totalfilters,
		cepstralCoefficients,
		_mIdctMatrix
		);

	//----------------------------------------------------------------------
	//  I give the max possible value to the parameters max_factors and max_perm
	//  May be to ajust this was necessary in the original fortran code to be
	//  use in computers with low memory.
	//----------------------------------------------------------------------
	//fft = new YARPFft(numSamples, numSamples);
	//fft = new YARPFft(2, 11);
	fft = new YARPFft(7, 4);

	Re = new double[numSamples]; // this contains the Re of both channels
	Im = new double[numSamples]; // this contains the Im of both channels
	_pSoundData = new double[numSamples]; // This contains the sound samples of
										  // one of the channels.
}