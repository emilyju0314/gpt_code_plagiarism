void TaskTree::Clear() {
  // It may be worth checking if this can be  optimized by sending the handles
  // in batches.

  for (auto& job : jobs_) {
    zx_handle_close(job.handle);
  }
  jobs_.clear();

  for (auto& process : processes_) {
    zx_handle_close(process.handle);
  }
  processes_.clear();

  for (auto& thread : threads_) {
    zx_handle_close(thread.handle);
  }
  threads_.clear();
}