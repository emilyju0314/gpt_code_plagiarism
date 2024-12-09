void Gllyap::set_viewport() {
	winh = (winh < 1)? 1: winh;
//	GLfloat ratio = GLfloat(winw) / GLfloat(winh);
	glViewport(0, 0, (GLsizei)winw, (GLsizei)winh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// set an orthogonal projection:
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	// make sure we are changing the model view matrix and not projection:
	glMatrixMode(GL_MODELVIEW);
	// reset the view:
	glLoadIdentity();
}