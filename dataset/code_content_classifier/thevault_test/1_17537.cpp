Worker(const std::string& name, const std::string& platform)
    : metadata_(name, platform) {
    this->status_ = WorkerStatus::kNew;
#ifdef PROTEUS_ENABLE_LOGGING
    this->logger_ = getLogger();
    if (this->logger_ == nullptr) {
      initLogging();
      this->logger_ = getLogger();
    }
#endif
    this->input_buffers_ = nullptr;
    this->output_buffers_ = nullptr;
    this->max_buffer_num_ = UINT_MAX;
    this->batch_size_ = 1;
  }