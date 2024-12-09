int
Tcl_AppInit(Tcl_Interp *interp)
{
#ifdef MEMDEBUG_SIMULATIONS
        extern MemTrace *globalMemTrace;
        globalMemTrace = new MemTrace;
#endif

	setup_floating_point_environment();
       
	if (Tcl_Init(interp) == TCL_ERROR ||
	    Otcl_Init(interp) == TCL_ERROR)
		return TCL_ERROR;

    if (Tk_Init(interp) == TCL_ERROR) {
	return TCL_ERROR;
    }


    Tcl_StaticPackage(interp, "Tk", Tk_Init, Tk_SafeInit);
#ifdef TK_TEST
    if (Tktest_Init(interp) == TCL_ERROR) {
	return TCL_ERROR;
    }
    Tcl_StaticPackage(interp, "Tktest", Tktest_Init,
            (Tcl_PackageInitProc *) NULL);
#endif /* TK_TEST */


    /*
     * Call the init procedures for included packages.  Each call should
     * look like this:
     *
     * if (Mod_Init(interp) == TCL_ERROR) {
     *     return TCL_ERROR;
     * }
     *
     * where "Mod" is the name of the module.
     */
#ifdef HAVE_LIBTCLDBG
	extern int Tcldbg_Init(Tcl_Interp *);   // hackorama
	if (Tcldbg_Init(interp) == TCL_ERROR) {
		return TCL_ERROR;
	}
#endif



	// copied from ns2.28's tclAppinit.cc
	Tcl_SetVar(interp, "tcl_rcFileName", "~/.ns.tcl", TCL_GLOBAL_ONLY);
	Tcl::init(interp, "ns");
	init_misc();
    et_ns_ptypes.load();
	et_ns_lib.load();

	// copied from ns2.28's old tkAppinit.cc

	// it seems that using tk8.4.5 this line isnt' needed anymore. enabling it produces an error.
	// HOWEVER, do enable it if using tk8.3 and below!
	// et_tk.load();                  //      <<<<-------- this line
	
    Tcl::instance().tkmain(Tk_MainWindow(interp));
    loadbitmaps(interp);


#ifdef TK_TEST
	if (Tcltest_Init(interp) == TCL_ERROR) {
		return TCL_ERROR;
	}
	Tcl_StaticPackage(interp, "Tcltest", Tcltest_Init,
			  (Tcl_PackageInitProc *) NULL);
#endif /* TK_TEST */

	return TCL_OK;
}