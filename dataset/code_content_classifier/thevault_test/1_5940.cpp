void
  UAbstractClient::processRecvBuffer()
  {
    while (binaryMode
           ? process_recv_buffer_binary_()
           : process_recv_buffer_text_())
      continue;
  }