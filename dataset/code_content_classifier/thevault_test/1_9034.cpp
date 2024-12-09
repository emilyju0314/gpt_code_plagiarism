void reshapeCallback(int w, int h) {
	// I didn't add a resize function, so the window will always be set to 1024, 768

	glutReshapeWindow(1024, 768);
	glMatrixMode(GL_PROJECTION);	// sets up a projection view
	glLoadIdentity();
	gluOrtho2D(0.0, 1024, 0.0, 768);		// sets the coords of the orthogonal plane
	glViewport(0, 0, 1024, 768);			// sets the viewed coords
}