Batcher::Batcher() {
  this->input_queue_ = std::make_shared<BlockingQueue<InterfacePtr>>();
  this->output_queue_ = std::make_shared<BatchPtrQueue>();
  this->batch_size_ = 1;
  this->status_ = BatcherStatus::kNew;
#ifdef PROTEUS_ENABLE_LOGGING
  this->logger_ = getLogger();
#endif
}