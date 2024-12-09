int PgmAgent::command (int argc, const char*const* argv)
{
  //  Tcl& tcl = Tcl::instance();

  if (argc == 2) {
    if (strcmp(argv[1], "print-stats") == 0) {
      print_stats();
      return (TCL_OK);
    }
  }
  else if (argc == 3) { //Set the Event Trace handle if Event Tracing is on
    if (strcmp(argv[1], "eventtrace") == 0) {
      et_ = (EventTrace *)TclObject::lookup(argv[2]);
      return (TCL_OK);
    }
  }

  return (Agent::command(argc, argv));
}