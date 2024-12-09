void mouseCallback(int button, int state, int x, int y) {
	y = height - y;	// reverse the y with the current height
	switch (getStage()) {
	case PRELOGIN:
		PreLoginMouse(button, state, x, y);
		break;
	case PRESTART:
		PrestartMouse(button, state, x, y);
		break;
	case RUNNING:
		RunningMouse(button, state, x, y);
		break;
	case PAUSED:
		PausedMouse(button, state, x, y);
		break;

	}
	glutPostRedisplay();
}