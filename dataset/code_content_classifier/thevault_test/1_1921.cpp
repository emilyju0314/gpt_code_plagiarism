void
runStdProgram(int argc, char** argv)
{
    // First initialize OpenGL context, so we can properly set the GL for CUDA.
    // This is necessary in order to achieve optimal performance with OpenGL/CUDA interop.
    if( false == initGL(&argc, argv)) 
    {
        return;
    }

    // Now initialize CUDA context (GL context has been created already)
    initCUDA(argc, argv, true);
    
    cutCreateTimer(&timer);
    cutResetTimer(timer);  

    // register callbacks
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutTimerFunc(REFRESH_DELAY, timerEvent, 0);

    // create menu
    glutCreateMenu(mainMenu);
    glutAddMenuEntry("Toggle CUDA processing [ ]", ' ');
    glutAddMenuEntry("Toggle animation [a]", 'a');
    glutAddMenuEntry("Increment blur radius [=]", '=');
    glutAddMenuEntry("Decrement blur radius [-]", '-');
    glutAddMenuEntry("Quit (esc)", '\033');
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    initGLBuffers();
#ifndef USE_TEXSUBIMAGE2D
    initCUDABuffers();
#endif

    // Creating the Auto-Validation Code
    if (g_bGLVerify) 
    {
        g_CheckRender = new CheckBackBuffer(window_width, window_height, 4);
        g_CheckRender->setPixelFormat(GL_RGBA);
        g_CheckRender->setExecPath(argv[0]);
        g_CheckRender->EnableQAReadback(true);
    }

    printf("\n"
        "\tControls\n"
		"\t(right click mouse button for Menu)\n"
		"\t[ ] : Toggle CUDA processing\n"
		"\t[a] : Toggle Animation\n"
		"\t[=] : Increment blur radious\n"
		"\t[-] : Decrement blur radious\n"
		"\t[esc] - Quit\n\n"
        );

    // start rendering mainloop
    glutMainLoop();

    // Normally unused return path
    if (!g_bQAReadback) {
        CleanupNoPrompt(EXIT_SUCCESS);
    } else {
        Cleanup(EXIT_SUCCESS);
    }
}