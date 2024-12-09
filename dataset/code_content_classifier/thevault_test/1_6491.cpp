void static_exit(void) {
		HINSTANCE hInstance = Tk_GetHINSTANCE();
		Tcl_LibMain(hInstance, DLL_PROCESS_DETACH, NULL);
		Tk_LibMain(hInstance, DLL_PROCESS_DETACH, NULL);
	}