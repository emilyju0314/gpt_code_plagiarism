sched_status::status_enum queued_fifo_scheduler::get_next(const size_t cpuid,
                                                          lvid_type& ret_vid) {
  queue_type& myqueue = out_queues[cpuid];
  // if the local queue is empty try to get a queue from the master
  out_queue_locks[cpuid].lock();
  if(myqueue.empty()) {
    master_lock.lock();
    // if master queue is empty... 
    if (!master_queue.empty()) {
      myqueue.swap(master_queue.front());
      master_queue.pop_front();
      master_lock.unlock();
    }
    else {
      master_lock.unlock();
      //try to steal from the inqueues
      for (size_t i = 0; i < in_queues.size(); ++i) {
        size_t idx = (i + multi * cpuid) % in_queues.size();
        if (!in_queues[idx].empty()) {
          in_queue_locks[idx].lock();
          // double check
          if(!in_queues[idx].empty()) {
            myqueue.swap(in_queues[idx]);
          }
          in_queue_locks[idx].unlock();
          if (!myqueue.empty()) break;
        } 
      }
    }
  }
  // end of get next
  bool good = false;
  while(!myqueue.empty()) {
    // not empty, pop and verify
    ret_vid = myqueue.front();
    myqueue.pop_front();
    if (ret_vid < num_vertices) {
      good = vertex_is_scheduled.clear_bit(ret_vid);
      if (good) break;
    }
  }
  out_queue_locks[cpuid].unlock();

  if(good) {
    return sched_status::NEW_TASK;
  } else {
    return sched_status::EMPTY;
  }
}