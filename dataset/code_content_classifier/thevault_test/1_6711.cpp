int EXPOO_Traffic::command(int argc, const char*const* argv){
        
        if(argc==3){
                if (strcmp(argv[1], "use-rng") == 0) {
                        burstlen_.seed((char *)argv[2]);
                        Offtime_.seed((char *)argv[2]);
                        return (TCL_OK);
                }
        }
        return Application::command(argc,argv);
}