void SVNetwork::Close() {
#  ifdef _WIN32
  closesocket(stream_);
#  else
  close(stream_);
#  endif
  // Mark stream_ as invalid.
  stream_ = -1;
}