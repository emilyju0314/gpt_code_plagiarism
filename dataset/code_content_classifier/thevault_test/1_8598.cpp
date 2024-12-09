static auto EnqueueAllJSONsInBuffer(std::string* json_buffer, std::byte* recv_buffer,
                                    size_t tcp_valid_bytes, JSONQueue* queue,
                                    uint64_t* seq, TimePoint receive_time,
                                    LatencyTracker* tracker = nullptr) -> size_t {
  size_t queued = 0;
  // TODO(johanpel): implement mechanism to allow newlines within JSON objects,
  //   this only works for non-pretty printed JSONs now.
  auto* recv_chars = reinterpret_cast<char*>(recv_buffer);

  // Scan the buffer for a newline.
  char* json_start = recv_chars;
  char* json_end = recv_chars + tcp_valid_bytes;
  size_t remaining = tcp_valid_bytes;
  do {
    json_end = static_cast<char*>(std::memchr(json_start, '\n', remaining));
    if (json_end == nullptr) {
      // Append the remaining characters to the JSON buffer.
      json_buffer->append(json_start, remaining);
      // We appended everything up to the end of the buffer, so we can set remaining
      // bytes to 0.
      remaining = 0;
    } else {
      // There is a newline. Only append the remaining characters to the json_msg.
      json_buffer->append(json_start, json_end - json_start);

      // Copy the JSON string into the consumption queue.
      auto pre_queue_time = Timer::now();
      queue->enqueue(JSONItem{*seq, *json_buffer});
      // Place the receive time for this JSON in the tracker.
      if (tracker != nullptr) {
        tracker->Put(*seq, 0, receive_time);
        tracker->Put(*seq, 1, pre_queue_time);
      }
      (*seq)++;
      queued++;

      // Clear the JSON string buffer. The implementation of std::string is allowed to
      // change its allocated buffer here, but there are no implementations that actually
      // do it, they retain the allocated buffer. An implementation using
      // std::vector<char> might be desired here just to make sure.
      json_buffer->clear();

      // Move the start to the character after the newline.
      json_start = json_end + 1;

      // Calculate the remaining number of bytes in the buffer.
      remaining = (recv_chars + tcp_valid_bytes) - json_start;
    }
    // Repeat until there are no remaining bytes.
  } while (remaining > 0);

  // Clear the buffer when finished.
  memset(recv_buffer, 0, ILLEX_DEFAULT_TCP_BUFSIZE);

  return queued;
}