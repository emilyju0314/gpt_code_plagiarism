int
Trace::nextLine() {
  char * position;

  if (direction_ == FORWARDS) {
    // moving forward through the trace file
    // We need to read in one line at a time
    nam_stream_->gets(pending_.image, sizeof(pending_.image));

    ++lineno_;
    if (nam_stream_->eof()) {
      Tcl& tcl = Tcl::instance();
      tcl.evalf("%s stopmaxtime %f", nam()->name(), pending_.time);
      return 0;
    }

  } else {
    // moving backwards through the trace file 
    position = nam_stream_->rgets(pending_.image, sizeof(pending_.image));

    lineno_--;
    if (position == NULL ) {
      fprintf(stderr, "nam file reading error.\n");
      return -1; // signal reading error
    }

    if (nam_stream_->tell() == 0) {
      // Beginning of file reached so we need to stop
      return -1;
    }  
  }

  return(nam_stream_->tell());
}