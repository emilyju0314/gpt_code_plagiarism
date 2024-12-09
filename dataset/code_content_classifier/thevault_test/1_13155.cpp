ThreadPool::ThreadPool() : terminated_(false) {
  auto thread_counts(std::max(std::thread::hardware_concurrency(), 
                     (unsigned int)1));
  try {
    for (unsigned int i = 0; i < thread_counts; i++) {
      threads_.push_back(std::thread(&ThreadPool::WorkerThread, this));
    }
  } catch (...) {
    terminated_.store(true);
  }
}