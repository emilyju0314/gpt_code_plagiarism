size_t DirectoryIterator::FileSize() const {
#if !defined(WEBRTC_WIN)
  return stat_.st_size;
#else
  return data_.nFileSizeLow;
#endif
}