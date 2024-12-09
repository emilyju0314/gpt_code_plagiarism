std::string DirectoryIterator::Name() const {
#if defined(WEBRTC_WIN)
  return ToUtf8(data_.cFileName);
#else
  assert(dirent_ != NULL);
  return dirent_->d_name;
#endif
}