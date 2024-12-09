SoundProcessing::SoundProcessing(const YARPString &iniFile, int outsize):
ild(NUM_ILD), itd(NUM_ITD)
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
	_BufferLength  = 8192;
	_iniFile       = iniFile;
	_outSize       = outsize;
	_SCOTfiltering = 0;

	_path.append(root);
	_path.append("/conf/babybot/"); 

	_k_gains.Resize(2); //This is the gain vector for the tilt and the pan
	_k_gains = __soundgain;

	//----------------------------------------------------------------------
	//  Just recover from the configuration file the real sound parameters the user
	//  is using  
	//----------------------------------------------------------------------
	file.set(_path, _iniFile);
	file.get("[GENERAL]" , "Channels"            , &_Channels            , 1);
	file.get("[GENERAL]" , "SamplesPerSec"       , &_SamplesPerSec       , 1);
	file.get("[GENERAL]" , "BitsPerSample"       , &_BitsPerSample       , 1);
	file.get("[GENERAL]" , "BufferLength"        , &_BufferLength        , 1);
	file.get("[GENERAL]" , "MicrophonesDistance" , &_microphonesdistance , 1);
	file.get("[GENERAL]" , "SCOTfiltering"       , &_SCOTfiltering       , 1);
	file.get("[GENERAL]" , "TempCrossCorrelation", &_TempCC              , 1);

	double maxITD = _microphonesdistance/331.7;
	shift         = int((maxITD * _SamplesPerSec) + 0.5 );   // what is the 0.5 for?
	windowMax     = 2 * shift + 1;
	double tmp1   = ((double) windowMax) / _SamplesPerSec;
	double tmp2   = (_BufferLength / (4.0 * _SamplesPerSec));
	windowTime    = tmp2 - tmp1;
	windowSize    = int (windowTime * _SamplesPerSec);
	timeMax       = windowSize + shift;

    numSamples     = _BufferLength/4;  
    numFreqSamples = numSamples/2 + 1; // Check SP documentation

	bias = 0;

	//----------------------------------------------------------------------
	//  I give the max possible value to the parameters max_factors and max_perm
	//  May be to ajust this was necessary in the original fortran code to be
	//  use in computers with low memory.
	//----------------------------------------------------------------------
	fft = new YARPFft(numSamples, numSamples);

	// allocate vectors
	corrVect            = new double[numSamples];
	crosscorrelation_Re = new double[2 * numSamples];
	corrVectFreq        = &crosscorrelation_Re[numSamples];
	crosscorrelation_Im = new double[numSamples];
	leftcorrelation_Re  = new double[numSamples];
	leftcorrelation_Im  = new double[numSamples];
	rightcorrelation_Re = new double[numSamples];
	rightcorrelation_Im = new double[numSamples];
	middleSampleRight   = new double[windowSize];
	middleSampleLeft    = new double[windowSize];
	SCOToperator_Re     = new double[numSamples];
	SCOToperator_Im     = new double[numSamples];
	Re = new double[2 * numSamples]; // this contains the Re of both channels
	Im = new double[2 * numSamples]; // this contains the Im of both channels

	//----------------------------------------------------------------------
	//  Initialize thresholds. These values have been optained from Lorenzo's
	//  code. May be the should be included in the sound.ini file and loaded
	//  dinamically....
	//----------------------------------------------------------------------
	thresholds.nvalidpoints = 200;
	thresholds.max_left     = 32000;
	thresholds.max_right    = 32000;
	thresholds.min_left     = 1000;
	thresholds.min_right    = 1000;
}