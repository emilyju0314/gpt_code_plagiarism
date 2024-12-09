void mouseCallback(int button, int state, int x, int y) {
	y = height - y;	// reverse the y with the current height
	cout << x << ", " << y << endl;
	mouseBoxSizeEditor(button, state, x, y);
	mouseEditorSubWindow(button, state, x, y);
	mouseLoadSaveOps(button, state, x, y);
	glutPostRedisplay();
}