size_t QuicStreamSequencerBufferPeer::Read(char* dest_buffer, size_t size) {
  iovec dest;
  dest.iov_base = dest_buffer, dest.iov_len = size;
  size_t bytes_read;
  std::string error_details;
  EXPECT_THAT(buffer_->Readv(&dest, 1, &bytes_read, &error_details),
              IsQuicNoError());
  return bytes_read;
}