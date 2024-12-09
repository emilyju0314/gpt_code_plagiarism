Trace::Trace(const char *fname, const char *animator) : 
  handlers_(0),
  nam_(0),
  skipahead_mode_(0),
  count_(0) {
  
  last_event_time_ = 0.0;

  // Connect to nam animator
  nam_ = (NetworkAnimator *)TclObject::lookup(animator);

  strncpy(fileName_, fname, sizeof(fileName_)-1);
  fileName_[sizeof(fileName_)-1] = 0;
  nam_stream_ = NamStream::open(fileName_);
  if (!nam_stream_->is_ok()) {
    delete nam_stream_;
    nam_stream_ = NULL;
    perror("nam: fdopen");
    // exit(1);
    return; // tr->valid() will check this
  }
  findLastLine();

  /*
   * Go to the beginning of the file, read the first line and
   * save its contents.
   */
  off_t pos = nam_stream_->seek(0, SEEK_SET);
  assert(pos == 0);

  /*
   * Minimum time on the nam time slider is the time of the first
   * trace event.
   */
  mintime_ = nextTime();
  now_ = mintime_;

  State::instance()->setTimes(mintime_, maxtime_);

  // Initialize ParseTable
  parse_table_ = new ParseTable(&pending_);
}