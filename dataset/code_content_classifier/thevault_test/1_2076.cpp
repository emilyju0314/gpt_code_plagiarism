void
runTest(int argc, char** argv)
{
    // First initialize OpenGL context, so we can properly set the GL for CUDA.
    // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
    if( false == initGL(argc, argv)) {
        return;
    }

	// Now initialize CUDA context (GL context has been created already)
	initCUDA(argc, argv);

	if( !cutCheckCmdLineFlag(argc, (const char**)argv, "noqatest") ||
		cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt"))
	{
        g_bQAReadback = true;
        animate = false;

		blur_radius = 2;
	}

    cutCreateTimer(&timer);
    cutResetTimer(timer);  

    // register callbacks
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    // create menu
    glutCreateMenu(mainMenu);
    glutAddMenuEntry("Toggle CUDA processing [ ]", ' ');
    glutAddMenuEntry("Toggle animation [a]", 'a');
    glutAddMenuEntry("Increment blur radius [=]", '=');
    glutAddMenuEntry("Decrement blur radius [-]", '-');
    glutAddMenuEntry("Quit (esc)", '\033');
    glutAttachMenu(GLUT_RIGHT_BUTTON);

	initGLBuffers();

//	atexit(cleanup);

    // Creating the Auto-Validation Code
    if (g_bQAReadback) {
		if (g_bFBODisplay) {
			g_CheckRender = new CheckFBO(window_width, window_height, 4);
		} else {
			g_CheckRender = new CheckBackBuffer(window_width, window_height, 4);
		}
        g_CheckRender->setPixelFormat(GL_RGBA);
        g_CheckRender->setExecPath(argv[0]);
        g_CheckRender->EnableQAReadback(true);
    }

    // start rendering mainloop
    glutMainLoop();

    cudaThreadExit();
}