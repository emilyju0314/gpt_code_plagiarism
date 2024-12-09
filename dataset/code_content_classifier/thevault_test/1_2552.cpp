void Parallel_File_Token_Stream::letter::fill_character_buffer_(vector<char> &comm_buffer) {
  using rtt_c4::broadcast;

  // The first value in the communications buffer will be a status code, which
  // if positive is the number of valid characters ini the buffer. This dictates
  // the maximum size needed for the buffer to be the maximum positive character
  // value, plus one (for the status code itself).

  // i points to the current position in the communications buffer. We
  // initialize it to 1 to reserve the first character for the status code.
  unsigned i = 1;
  if (is_io_processor_) {
    // Read up to numeric_limits<signed char>::max() characters from the input
    // file.
    while (i < static_cast<unsigned>(numeric_limits<signed char>::max() + 1)) {
      char const c = static_cast<char>(infile_.get());
      if (infile_.eof() || infile_.fail())
        break;
      comm_buffer[i++] = c;
    }

    if (i > 1) {
      // If there is an end or error condition, but one or more characters were
      // successfully read prior to encountering the end or error condition,
      // wait to transmit the end or error until the next call to
      // fill_character_buffer.

      // Set the status code to the number of valid characters read.
      comm_buffer[0] = static_cast<char>(i - 1);
    } else if (infile_.eof() && !infile_.bad()) {
      // Normal end of file condition.
      comm_buffer[0] = '\0';
    } else {
      // Something went seriously wrong.
      comm_buffer[0] = static_cast<char>(-1);
    }
  }

  auto first = comm_buffer.begin();
  auto last = first + i;

  rtt_c4::broadcast(first, last, first);

  if (comm_buffer[0] == '\0') {
    at_eof_ = true;
  } else if (comm_buffer[0] == static_cast<char>(-1)) {
    at_error_ = true;
  }

  Ensure(check_class_invariants());
}