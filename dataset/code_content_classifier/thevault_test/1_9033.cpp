void keyboardCallback(unsigned char key, int x, int y) {
	switch (getStage()) {
	case PRELOGIN:
		PreLoginKeyboard(key, x, y);
		break;

	}
	glutPostRedisplay(); // call the display function
}