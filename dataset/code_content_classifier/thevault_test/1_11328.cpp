sched_status::status_enum priority_scheduler::get_next(const size_t cpuid,
                                                       lvid_type& ret_vid) {
  /* Check all of my queues for a task */
  // begin scanning from the machine's current queue
  size_t initial_idx = (current_queue[cpuid] % multi) + cpuid * multi;
  for(size_t i = 0; i < queues.size(); ++i) {
    const size_t idx = (initial_idx + i) % queues.size();
    // increment the current queue as long as I am scanning with in the 
    // queues owned by this machine
    current_queue[cpuid] += (i < multi);

    // pick up the lock
    bool good = false;
    locks[idx].lock();
    while(!queues[idx].empty() && queues[idx].top().second >= min_priority) {
      // not empty, pop and verify
      ret_vid = queues[idx].pop().first;
      if (ret_vid < num_vertices) {
        good = vertex_is_scheduled.clear_bit(ret_vid);
        if (good) break;
      }
      else continue;
    }
    locks[idx].unlock();
    // managed to retrieve a task
    if(good) {
      return sched_status::NEW_TASK;
    }
  }
  return sched_status::EMPTY;     
}