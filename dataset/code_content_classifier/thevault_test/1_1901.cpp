CUTBoolean runTest(int argc, char** argv)
{
    if (!cutCheckCmdLineFlag(argc, (const char **)argv, "noqatest") ||
		cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt")) 
	{
        g_bQAReadback = true;
        fpsLimit = frameCheckNumber;
    }

    // First initialize OpenGL context, so we can properly set the GL for CUDA.
    // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
    if (CUTFalse == initGL(argc, argv)) {
        return CUTFalse;
    }

	// use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilGLDeviceInit(argc, argv);
    else {
        cudaGLSetGLDevice( cutGetMaxGflopsDeviceId() );
    }

    // Create the CUTIL timer
    cutilCheckError( cutCreateTimer( &timer));

    // register callbacks
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    if (g_bQAReadback) {
        g_CheckRender = new CheckBackBuffer(window_width, window_height, 4);
        g_CheckRender->setPixelFormat(GL_RGBA);
        g_CheckRender->setExecPath(argv[0]);
        g_CheckRender->EnableQAReadback(true);
    }

    // create VBO
    createVBO(&vbo);

    // run the cuda part
    runCuda(vbo);

    // check result of Cuda step
    checkResultCuda(argc, argv, vbo);

    atexit(cleanup);

    // start rendering mainloop
    glutMainLoop();

    cudaThreadExit();

	return CUTTrue;
}