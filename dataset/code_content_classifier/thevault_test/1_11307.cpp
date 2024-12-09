inline void in_parallel(const std::function<void (size_t thread_id, 
                                                  size_t num_threads)>& fn) {
  size_t nworkers = thread_pool::get_instance().size();

  if (thread::get_tls_data().is_in_thread() || nworkers <= 1) {

    fn(0, 1);
    return;

  } else {

    parallel_task_queue threads(thread_pool::get_instance());

    for (size_t i = 0;i < nworkers; ++i) {
      threads.launch([&fn, i, nworkers]() { fn(i, nworkers); }, i);
    }
    threads.join();
  }
}