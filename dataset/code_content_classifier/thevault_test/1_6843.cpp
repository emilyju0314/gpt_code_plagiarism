int POO_Traffic::command(int argc, const char*const* argv){
        
	Tcl& tcl = Tcl::instance();
        if(argc==3){
                if (strcmp(argv[1], "use-rng") == 0) {
			rng_ = (RNG*)TclObject::lookup(argv[2]);
			if (rng_ == 0) {
				tcl.resultf("no such RNG %s", argv[2]);
				return(TCL_ERROR);
			}                        
			return (TCL_OK);
                }
        }
        return Application::command(argc,argv);
}