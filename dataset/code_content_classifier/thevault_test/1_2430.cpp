bool QuoWrapper::is_initialized() {
  if (instance == nullptr)
    instance = new QuoWrapper;
  return instance != nullptr;
}