void
Trace::scan() {
  char * time;
  /*
   * Read the next line in the trace file and store its contents
   * depending on line type.
   */
  while (1) {
    TraceEvent & p = pending_;
    time = p.image;

    p.offset = nextLine();

    if (p.offset <= 0) {
      // We reached the beginning of the file
      pending_.time = TIME_EOF;
      // Reset the last event time tracker
      last_event_time_ = 0.0;
      //fprintf(stderr, "EOF Reached.\n");
      return;
    }

    // -----------------------------------------------
    // This -t * line skipping is a hack to
    // enable the wireless code to work properly.
    // All the -t * lines are parsed in tcl files
    // before the animation starts and reparsing them
    // seems to screw up the wireless stuff.
    // ------------------------------------------------
    
    // Skip over -t * lines
    while (*time != '\0') {
      // Find the -t flag
      if (*time == '-') {
        time++;
        if (*time == 't') {
          // Eat the whitespace
          time++;
          while (*time == ' ' || *time == '\t') {
            time++;
          } 

          // We should be pointing to the
          // -t flag value now
          if (*time == '*') {
            break;
          }
        }
      } else {
        time++;
      }
    }
    
    if (*time == '*') {
      // Notify user if their tracefile has initialization events that
      // are mixed in with animation events
      switch (direction_) {
        case FORWARDS:
          // last_event_time_ is initialized to 0.0 since events cannot happen before this time.
          if (last_event_time_ != 0.0) {
            fprintf(stderr, "Warning: Initialization event is mixed in with animation events.\n");
            fprintf(stderr, "%s", p.image);
            fprintf(stderr, "The above event should occur before all -t <time> animation events.\n\n");
            fprintf(stderr, "last_time_event_ %f\n", last_event_time_);
          }
          break;
      }
      last_event_time_ = 0.0;

      if (p.offset <= 0) {
	      pending_.time = TIME_EOF;
	      //fprintf(stderr, "EOF Reached.\n");
	      return;
      }
      continue;
    } 

    if (parse_table_->parseLine(p.image)) {
      switch (direction_) {
        // Notify user if their tracefile has records that are out of order
        case FORWARDS:
          if (pending_.time < last_event_time_) {
            fprintf(stderr, "Warning: Tracefile events are not sorted by time.\n");
            fprintf(stderr, "%s", p.image);
            fprintf(stderr, "The above event should occur at or after -t %f.\n\n",
                            last_event_time_);
          }
          break;
        case BACKWARDS:
          if (pending_.time > last_event_time_ && last_event_time_ != 0.0) {
            fprintf(stderr, "Warning: Tracefile events are not sorted by time.\n");
            fprintf(stderr, "%s", p.image);
            fprintf(stderr, "The above event should occur at or before -t %f.\n\n",
                            last_event_time_);
          }
          break;
      }
      last_event_time_ = pending_.time;
      return;

    } else {
      fprintf(stderr, "Parsing error in event.\n");
    }
    
  } // end while
  /* NOTREACHED */
}