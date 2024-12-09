thread_t* Scheduler::FindEarlierDeadlineThread(SchedTime eligible_time, SchedTime finish_time) {
  thread_t* const eligible_thread = FindEarliestEligibleThread(&deadline_run_queue_, eligible_time);
  const bool found_earlier_deadline =
      eligible_thread && eligible_thread->scheduler_state.finish_time_ < finish_time;
  return found_earlier_deadline ? eligible_thread : nullptr;
}