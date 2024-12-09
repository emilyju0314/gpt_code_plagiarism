void Timer(int m) {

	glutPostRedisplay();
	glutTimerFunc(1000.0/FPS, Timer, 0);
}