char *SVNetwork::Receive() {
  char *result = nullptr;
  if (buffer_ptr_ != nullptr) {
    result = strtok_r(nullptr, "\n", &buffer_ptr_);
  }

  // This means there is something left in the buffer and we return it.
  if (result != nullptr) {
    return result;
    // Otherwise, we read from the stream_.
  } else {
    buffer_ptr_ = nullptr;

    // The timeout length is not really important since we are looping anyway
    // until a new message is delivered.
    struct timeval tv;
    tv.tv_sec = 10;
    tv.tv_usec = 0;

    // Set the flags to return when the stream_ is ready to be read.
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(stream_, &readfds);

    int i = select(stream_ + 1, &readfds, nullptr, nullptr, &tv);

    // The stream_ died.
    if (i == 0) {
      return nullptr;
    }

    // Read the message buffer.
    i = recv(stream_, msg_buffer_in_, kMaxMsgSize, 0);

    // Server quit (0) or error (-1).
    if (i <= 0) {
      return nullptr;
    }
    msg_buffer_in_[i] = '\0';
    // Setup a new string tokenizer.
    return strtok_r(msg_buffer_in_, "\n", &buffer_ptr_);
  }
}