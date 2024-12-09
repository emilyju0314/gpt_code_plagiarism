void LibeventMasterThread::DispatchConnection(int new_conn_fd,
                                              short event_flags) {
  char buf[1];
  buf[0] = 'c';
  auto &threads = GetWorkerThreads();

  // Dispatch by rand number
  int thread_id = next_thread_id_;

  // update next threadID
  next_thread_id_ = (next_thread_id_ + 1) % num_threads_;

  std::shared_ptr<LibeventWorkerThread> worker_thread = threads[thread_id];
  LOG_DEBUG("Dispatching connection to worker %d", thread_id);

  std::shared_ptr<NewConnQueueItem> item(
      new NewConnQueueItem(new_conn_fd, event_flags, CONN_READ));
  worker_thread->new_conn_queue.Enqueue(item);

  if (write(worker_thread->new_conn_send_fd, buf, 1) != 1) {
    LOG_ERROR("Failed to write to thread notify pipe");
  }
}