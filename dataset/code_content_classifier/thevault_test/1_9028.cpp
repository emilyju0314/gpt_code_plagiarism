void reshapeCallback(int w, int h) {
	// I didn't add a resize function, so the window will always be set to 1024, 768
	glutReshapeWindow(1400, 770);
	glMatrixMode(GL_PROJECTION);	// sets up a projection view
	glLoadIdentity();
	gluOrtho2D(0.0, 1400, 0.0, 770);		// sets the coords of the orthogonal plane
	glViewport(0, 0, 1400, 770);			// sets the viewed coords
}