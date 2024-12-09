LibeventWorkerThread::LibeventWorkerThread(const int thread_id)
    : LibeventThread(thread_id, event_base_new()), new_conn_queue(QUEUE_SIZE) {
  int fds[2];
  if (pipe(fds)) {
    LOG_ERROR("Can't create notify pipe to accept connections");
    exit(1);
  }
  // send_fd is used by the master thread, received_fd used by worker thread
  new_conn_receive_fd = fds[0];
  new_conn_send_fd = fds[1];

  // Listen for notifications from the master thread
  new_conn_event_ = event_new(libevent_base_, new_conn_receive_fd,
                              EV_READ | EV_PERSIST, WorkerHandleNewConn, this);

  if (event_add(new_conn_event_, 0) == -1) {
    LOG_ERROR("Can't monitor libevent notify pipe\n");
    exit(1);
  }
}