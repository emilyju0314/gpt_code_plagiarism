thread_t* Scheduler::DequeueEarlierDeadlineThread(SchedTime eligible_time, SchedTime finish_time) {
  LocalTraceDuration trace{"dequeue_earlier_deadline_thread"_stringref};
  thread_t* const eligible_thread = FindEarlierDeadlineThread(eligible_time, finish_time);
  return eligible_thread ? deadline_run_queue_.erase(*eligible_thread) : nullptr;
}