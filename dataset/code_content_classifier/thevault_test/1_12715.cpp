TetgenWin(int x, int y, int w, int h) : FlLayout(0, 0, w, h) {
		create("Button", TESTWIN_LOADOBJ_BUTTON, TESTWIN_LOADOBJ_BUTTON);
		create("Button", TESTWIN_POINT_BUTTON, TESTWIN_POINT_BUTTON);
		create("Button", TESTWIN_BACK_MESH_BUTTON, TESTWIN_BACK_MESH_BUTTON);
		create("Button", TESTWIN_LINE_BUTTON, TESTWIN_LINE_BUTTON);
		create("Button", TESTWIN_VOLUME_BUTTON, TESTWIN_VOLUME_BUTTON);
		create("Button", TESTWIN_LOADRGBD_BUTTON, TESTWIN_LOADRGBD_BUTTON);
		create("Button", TESTWIN_SURFACE_BUTTON, TESTWIN_SURFACE_BUTTON);
		create("Button", TESTWIN_TETRAHEDRON_BUTTON, TESTWIN_TETRAHEDRON_BUTTON);
		//create("Button", TESTWIN_CUT_BUTTON, TESTWIN_CUT_BUTTON);
		updateLayout();
	}