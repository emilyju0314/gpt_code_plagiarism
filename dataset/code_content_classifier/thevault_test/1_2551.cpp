void Parallel_File_Token_Stream::fill_character_buffer_() {
  using rtt_c4::broadcast;

  // The first value in the communications buffer will be a status code, which
  // if positive is the number of valid characters ini the buffer. This dictates
  // the maximum size needed for the buffer to be the maximum positive character
  // value, plus one (for the status code itself).
  vector<char> comm_buffer(numeric_limits<signed char>::max() + 1);

  if (letter_ != nullptr) {
    letter_->fill_character_buffer_(comm_buffer);
  } else {
    comm_buffer[0] = '\0';
  }

  if (comm_buffer[0] == '\0' || comm_buffer[0] == static_cast<char>(-1)) {
    character_push_back_('\0');
  } else {
    // Set i to point to the end of the valid sequence of characters in the
    // communications buffer.
    unsigned i = 1 + comm_buffer[0];

    // Make sure this is not past the end of the buffer. This should not be
    // possible unless the data has somewhow become corrupted during
    // transmission.
    if (i > static_cast<unsigned>(numeric_limits<signed char>::max() + 1)) {
      throw runtime_error("interprocessor communications corrupted");
    }

    // Copy the transmitted characters into the local character buffer.
    auto first = comm_buffer.begin();
    auto last = first + i;

    for (auto iter = first + 1; iter != last; ++iter) {
      character_push_back_(*iter);
    }
  }
}