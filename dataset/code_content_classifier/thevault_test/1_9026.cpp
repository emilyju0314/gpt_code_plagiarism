void displayCallback(void) {
	glClearColor(0.78, 0.75, 0.78, 1.0); // make a nice, light gray, background, for pre-login.
	glClear(GL_COLOR_BUFFER_BIT);	// clear the screen
	glLineWidth(1.5);
	drawBox(1, height-1, 1025, height-769, white, black); // the outline of our 'editor' sub-window

	drawBoxSizeEditor();
	drawEditorSubWindow();
	drawLoadSaveOps();
									// Swap the buffer (display everything created above)
	glutSwapBuffers();
}