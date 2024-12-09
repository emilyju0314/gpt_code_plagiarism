void Trace::findLastLine() {
  off_t pos;

  // should initialize it
  direction_ = FORWARDS;
  pending_.time = 0.0;
  pending_.image[0] = 0;

  /*
   * Fake it?
   */
  if (!nam_stream_->seekable()) {
    maxtime_ = 0.0;
    return;
  }

  /*
   * If we can, find the end of time.
   */
  char buf[TRACE_LINE_MAXLEN+1];

  /* is there stuff in the file */
  nam_stream_->seek(0, SEEK_END);
  if (nam_stream_->tell() <= 1) {
    fprintf(stderr, "nam: empty trace file `%s'.", fileName_);
    exit(1);
  }

  /*
   * If the file is larger than 'buf', go to the end of the file
   * at the point just large enough to fit into 'buf'.
   */
  if (nam_stream_->tell() > (off_t)(sizeof(buf) - 1)) {
    pos = nam_stream_->seek(- (sizeof(buf) - 1), SEEK_CUR);
    assert(pos != -1);
  } else 
    /* If the file is smaller than 'buf', go to the head of file */
    nam_stream_->seek(0, SEEK_SET);

  int n = nam_stream_->read(buf, sizeof(buf) - 1);
  if (n < 0) {
    perror("read");
    exit(1);
  }
  buf[n] = 0;

  /*
   * This next check is bogus, but zlib fails it.
   * Go figure.
   * Fortunately compressed files should not be seekable.
   */
  pos = nam_stream_->tell();
  assert(pos != -1);

  /* Error if the last line doesn't have '\n' in it. */
  char *cp = strrchr(buf, '\n');
  if (cp == 0) {
    fprintf(stderr, "nam: error, missing newline on the last line of `%s'.",
      fileName_);
    exit(1);
  }

  /*
   * Look for the first '\n' and check if the line following
   * it has the correct type, i.e., it starts with any of the
   * characters in [h+-dv].
   */
  *cp = 0;
  cp = strrchr(buf, '\n');
  if (cp == 0 || strchr("h+-dvrRanlfDEGPAmVNXWT", *++cp) == 0) {
    fprintf(stderr, "nam: no dynamic animation events in `%s'.\n", fileName_);
    maxtime_ = 0.0;
    return;
    //fprintf(stderr, "     Unknown event %s\n", buf);
    //exit(1);
  }

  /*
   * Compute the time interval from the beginning of the trace
   * to the end.
   * XXX this should include the duration of the last event but
   *     since we changed the format of 'size' from 'time' to
   *     'bytes', we can no longer figure this out.
   */
  double time = 0.;
  (void)sscanf(++cp, " -t %lg", &time);
  maxtime_ = time;
}