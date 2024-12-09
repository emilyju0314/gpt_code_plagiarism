void ifpstream::fill_buffers(unsigned const buffer_size) {
  // initialize N process vector of buffer sizes
  std::vector<unsigned> buffer_sizes(rtt_c4::nodes(), 0);
  // fill in local buffer size
  buffer_sizes[rtt_c4::node()] = buffer_size;
  // reduce buffer_size to all ranks
  rtt_c4::global_sum(&buffer_sizes[0], rtt_c4::nodes());

  if (rtt_c4::node() == 0) {
    // populate node zero buffer
    std::string local_string(buffer_size, '\0');
    in_.read(&local_string[0], buffer_size);
    str(local_string);
    // loop over and broadcast remaining buffers
    for (int node = 1; node < rtt_c4::nodes(); node++) {
      std::string broadcast_string(buffer_sizes[node], '\0');
      in_.read(&broadcast_string[0], buffer_sizes[node]);
      rtt_c4::send(&broadcast_string[0], buffer_sizes[node], node);
    }
  } else {
    // populate local buffer
    std::string local_string(buffer_size, '\0');
    rtt_c4::receive(&local_string[0], buffer_size, 0);
    str(local_string);
  }
}