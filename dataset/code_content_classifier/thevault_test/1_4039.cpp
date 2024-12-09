void ProcessGroupCNCL::WorkCNCL::synchronize() {
  auto current_queue = torch_mlu::getCurrentQueue();
  notifier_.wait(current_queue);

  if (blockingWait_) {
    current_queue.synchronize();
  }

  if (!barrier_tensors_.empty()) {
    torch_mlu::mlu::MLUGuard guard(devices_[0]);
    TORCH_CNRT_CHECK(cnrtSyncDevice());
  }

  return;
}