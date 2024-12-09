LibeventMasterThread::LibeventMasterThread(const int num_threads,
                                           struct event_base *libevent_base)
    : LibeventThread(MASTER_THREAD_ID, libevent_base),
      num_threads_(num_threads),
      next_thread_id_(0) {
  
  auto &threads = GetWorkerThreads();


  // register thread to epoch manager.
  if (concurrency::EpochManagerFactory::GetEpochType() == EpochType::DECENTRALIZED_EPOCH) {
    
    for (int thread_id = 0; thread_id < num_threads; thread_id++) {
      concurrency::EpochManagerFactory::GetInstance().RegisterThread(thread_id);
    }
  }

  // create worker threads.
  for (int thread_id = 0; thread_id < num_threads; thread_id++) {

    threads.push_back(std::shared_ptr<LibeventWorkerThread>(
        new LibeventWorkerThread(thread_id)));
    thread_pool.SubmitDedicatedTask(LibeventMasterThread::StartWorker,
                                    threads[thread_id].get());
  }
  // TODO wait for all threads to be up before exit from Init()
  // TODO replace sleep with future/promises
  sleep(1);
}