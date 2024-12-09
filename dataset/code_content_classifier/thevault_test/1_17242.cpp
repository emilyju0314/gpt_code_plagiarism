bool LibeventSocket::ReadPacketHeader() {
  size_t initial_read_size = sizeof(int32_t);
  if (pkt_manager.is_started == true) {
    // All packets other than the startup packet have a 5B header
    initial_read_size++;
  }
  // check if header bytes are available
  if (IsReadDataAvailable(initial_read_size) == false) {
    // nothing more to read
    return false;
  }

  // get packet size from the header
  if (pkt_manager.is_started == true) {
    // Header also contains msg type
    rpkt.msg_type =
        static_cast<NetworkMessageType>(rbuf_.GetByte(rbuf_.buf_ptr));
    // extract packet size
    GetSizeFromPktHeader(rbuf_.buf_ptr + 1);
  } else {
    GetSizeFromPktHeader(rbuf_.buf_ptr);
  }

  // do we need to use the extended buffer for this packet?
  rpkt.is_extended = (rpkt.len > rbuf_.GetMaxSize());

  if (rpkt.is_extended) {
    LOG_DEBUG("Using extended buffer for pkt size:%ld", rpkt.len);
    // reserve space for the extended buffer
    rpkt.ReserveExtendedBuffer();
  }

  // we have processed the data, move buffer pointer
  rbuf_.buf_ptr += initial_read_size;
  rpkt.header_parsed = true;

  return true;
}