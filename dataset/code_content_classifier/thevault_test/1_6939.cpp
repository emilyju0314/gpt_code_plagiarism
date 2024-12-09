int RapAgent::command(int argc, const char*const* argv)
{
	if (argc == 2) {
		if (strcmp(argv[1], "start") == 0) {
			start();
			// return TCL_OK, so the calling function knows that 
			// the command has been processed
			return (TCL_OK);
		} else if (strcmp(argv[1], "stop") == 0) {
			stop();
			return (TCL_OK);
		} else if (strcmp(argv[1], "listen") == 0) {
			listen();
			return (TCL_OK);
		}
	} else if (argc == 3) {
                if (strcmp(argv[1], "advanceby") == 0) {
                        advanceby(atoi(argv[2]));
                        return (TCL_OK);
                }
	}


	// If the command hasn't been processed by RapAgent()::command,
	// call the command() function for the base class
	return (Agent::command(argc, argv));
}