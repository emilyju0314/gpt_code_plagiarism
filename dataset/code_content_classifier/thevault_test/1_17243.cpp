bool LibeventSocket::ReadPacket() {
  if (rpkt.is_extended) {
    // extended packet mode
    auto bytes_available = rbuf_.buf_size - rbuf_.buf_ptr;
    auto bytes_required = rpkt.ExtendedBytesRequired();
    // read minimum of the two ranges
    auto read_size = std::min(bytes_available, bytes_required);
    rpkt.AppendToExtendedBuffer(rbuf_.Begin() + rbuf_.buf_ptr,
                                rbuf_.Begin() + rbuf_.buf_ptr + read_size);
    // data has been copied, move ptr
    rbuf_.buf_ptr += read_size;
    if (bytes_required > bytes_available) {
      // more data needs to be read
      return false;
    }
    // all the data has been read
    rpkt.InitializePacket();
    return true;
  } else {
    if (IsReadDataAvailable(rpkt.len) == false) {
      // data not available yet, return
      return false;
    }
    // Initialize the packet's "contents"
    rpkt.InitializePacket(rbuf_.buf_ptr, rbuf_.Begin());
    // We have processed the data, move buffer pointer
    rbuf_.buf_ptr += rpkt.len;
  }
  return true;
}