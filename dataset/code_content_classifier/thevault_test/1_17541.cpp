void Manager::shutdown() {
  auto request = std::make_shared<UpdateCommand>(UpdateCommandType::Shutdown);
  this->update_queue_->enqueue(request);
  if (this->update_thread_.joinable()) {
    this->update_thread_.join();
  }
}