CUTBoolean runTest(int argc, char** argv)
{
    // Create the CUTIL timer
    cutilCheckError( cutCreateTimer( &timer));
    
    if (g_bQAReadback) {
		// use command-line specified CUDA device, otherwise use device with highest Gflops/s
		if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") ) {
			cutilDeviceInit(argc, argv);
		} else {
			cudaSetDevice( cutGetMaxGflopsDeviceId() );
		}
		
		// create VBO
		createVBO(NULL, NULL, 0);
    } else {
		// First initialize OpenGL context, so we can properly set the GL for CUDA.
		// This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
		if (CUTFalse == initGL(&argc, argv)) {
			return CUTFalse;
		}
		// use command-line specified CUDA device, otherwise use device with highest Gflops/s
		if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") ) {
			cutilGLDeviceInit(argc, argv);
		} else {
			cudaGLSetGLDevice( cutGetMaxGflopsDeviceId() );
		}
		
		// register callbacks
		glutDisplayFunc(display);
		glutKeyboardFunc(keyboard);
		glutMouseFunc(mouse);
		glutMotionFunc(motion);
		
		// create VBO
		createVBO(&vbo, &cuda_vbo_resource, cudaGraphicsMapFlagsWriteDiscard);
    }
    
    if (g_bQAReadback) {
        g_CheckRender = new CheckBackBuffer(window_width, window_height, 4, false);
        g_CheckRender->setPixelFormat(GL_RGBA);
        g_CheckRender->setExecPath(argv[0]);
        g_CheckRender->EnableQAReadback(true);

        runAutoTest();
    } else {
        if (g_bGLVerify) {
            g_CheckRender = new CheckBackBuffer(window_width, window_height, 4);
            g_CheckRender->setPixelFormat(GL_RGBA);
            g_CheckRender->setExecPath(argv[0]);
            g_CheckRender->EnableQAReadback(true);
        }

        // run the cuda part
        runCuda(&cuda_vbo_resource);
    }

    // check result of Cuda step
    checkResultCuda(argc, argv, vbo);

    if (!g_bQAReadback) {
	    atexit(cleanup);
    	
	    // start rendering mainloop
	    glutMainLoop();
    }
	return CUTTrue;
}