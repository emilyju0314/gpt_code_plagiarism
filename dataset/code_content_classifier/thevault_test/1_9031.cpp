void displayCallback(void) {
	switch (getStage()) {
	case PRELOGIN:
		glClearColor(0.78, 0.75, 0.78, 1.0); // make a nice, light gray, background, for pre-login.
		glClear(GL_COLOR_BUFFER_BIT);	// clear the screen
		PreLoginDrawing();
		break;

	case PRESTART:
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		PrestartDrawing();
		break;

	case RUNNING:
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		RunningDrawing();
		break;

	case PAUSED:
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		PausedDrawing();
		break;

	default:
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		drawText("An error has occured", 400, 400);
		break;
	}
	// Swap the buffer (display everything created above)
	glutSwapBuffers();
}