int PgmSender::command(int argc, const char*const* argv)
{
  if (argc == 2) {
    if (strcmp(argv[1], "start-SPM") == 0) {
      start();
      return (TCL_OK);
    }
    if (strcmp(argv[1], "stop-SPM") == 0) {
      stop();
      return (TCL_OK);
    }
    if (strcmp(argv[1], "print-stats") == 0) {
      print_stats();
      return (TCL_OK);
    }
  }
  else if (argc == 3) { 	//If Event Trace is on, set the Event trace handle
    if (strcmp(argv[1], "eventtrace") == 0) {
      et_ = (EventTrace *)TclObject::lookup(argv[2]);
      return (TCL_OK);
    }
  }

  return (Agent::command(argc, argv));
}