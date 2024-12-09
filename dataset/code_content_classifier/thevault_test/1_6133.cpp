inline int DragonflyResources::_initialize (const DragonflyOpenParameters& params)
{
	FlyCaptureError   error = FLYCAPTURE_OK;

	// LATER: add a camera_init function

	sizeX = params._size_x;
	sizeY = params._size_y;

	// Create the context.
	if (!_validContext)
	{
		error = flycaptureCreateContext( &context );
		if (error != FLYCAPTURE_OK)
			return YARP_FAIL;
		_validContext = true;
		// Initialize the camera.
		error = flycaptureInitialize( context, params._unit_number );
		if (error != FLYCAPTURE_OK)
			return YARP_FAIL;
	}
	
	// Setup Camera Parameters, Magic Numbers :-)
	_setBrightness(0);
	_setExposure(300);
	_setWhiteBalance(20, 50); 
	_setShutter(320);	// x * 0.0625 = 20 mSec = 50 Hz
	_setGain(700);		// x * -0.0224 = -11.2dB
	
	// Set color reconstruction method
	error = flycaptureSetColorProcessingMethod(context, FLYCAPTURE_NEAREST_NEIGHBOR_FAST); // Should be an Option
	if (error != FLYCAPTURE_OK)
		return YARP_FAIL;

	// Set Acquisition Timeout
	error = flycaptureSetGrabTimeoutEx(context, 200);
	if (error != FLYCAPTURE_OK)
		return YARP_FAIL;
	// Buffers
	_prepareBuffers ();

	// Start Acquisition
	if (!_acqStarted)
	{
		error = flycaptureStart(	context, 
							FLYCAPTURE_VIDEOMODE_640x480Y8,
							FLYCAPTURE_FRAMERATE_30 );  
		if (error != FLYCAPTURE_OK)
			return YARP_FAIL;
		_acqStarted = true;
	}
	
	return YARP_OK;
}