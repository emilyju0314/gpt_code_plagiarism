thread_t* Scheduler::EvaluateNextThread(SchedTime now, thread_t* current_thread,
                                        bool timeslice_expired, SchedDuration total_runtime_ns) {
  LocalTraceDuration trace{"find_thread"_stringref};

  const bool is_idle = thread_is_idle(current_thread);
  const bool is_active = current_thread->state == THREAD_READY;
  const bool is_deadline = IsDeadlineThread(current_thread);
  const bool is_new_deadline_eligible = IsDeadlineThreadEligible(now);

  const cpu_num_t current_cpu = arch_curr_cpu_num();
  const cpu_mask_t current_cpu_mask = cpu_num_to_mask(current_cpu);
  const cpu_mask_t active_mask = mp_get_active_mask();

  const bool needs_migration =
      (GetEffectiveCpuMask(active_mask, current_thread) & current_cpu_mask) == 0;

  if (is_active && unlikely(needs_migration)) {
    // The current CPU is not in the thread's affinity mask, find a new CPU
    // and move it to that queue.
    current_thread->state = THREAD_READY;
    Remove(current_thread);

    const cpu_num_t target_cpu = FindTargetCpu(current_thread);
    Scheduler* const target = Get(target_cpu);
    DEBUG_ASSERT(target != this);

    target->Insert(now, current_thread);
    mp_reschedule(cpu_num_to_mask(target_cpu), 0);
  } else if (is_active && likely(!is_idle)) {
    if (timeslice_expired) {
      // If the timeslice expired insert the current thread into the run queue.
      QueueThread(current_thread, Placement::Insertion, now, total_runtime_ns);
    } else if (is_new_deadline_eligible && is_deadline) {
      // The current thread is deadline scheduled and there is at least one
      // eligible deadline thread in the run queue: select the eligible thread
      // with the earliest deadline, which may still be the current thread.
      const SchedTime deadline_ns = current_thread->scheduler_state.finish_time_;
      if (thread_t* const earlier_thread = DequeueEarlierDeadlineThread(now, deadline_ns);
          earlier_thread != nullptr) {
        QueueThread(current_thread, Placement::Preemption, now, total_runtime_ns);
        return earlier_thread;
      }

      // The current thread still has the earliest deadline.
      return current_thread;
    } else if (is_new_deadline_eligible && !is_deadline) {
      // The current thread is fair scheduled and there is at least one eligible
      // deadline thread in the run queue: return this thread to the run queue.
      QueueThread(current_thread, Placement::Preemption, now, total_runtime_ns);
    } else {
      // The current thread has remaining time and no eligible contender.
      return current_thread;
    }
  } else if (!is_active && likely(!is_idle)) {
    // The current thread is no longer ready, remove its accounting.
    Remove(current_thread);
  }

  // The current thread is no longer running or has returned to the run queue,
  // select another thread to run. If there is an eligible deadline thread, it
  // takes precedence over available fair threads.
  //
  // Note the that predicates in this block must be evaluated here, since the
  // operations above may change the queues and invalidate the predicates
  // evaluated at the start of this method.
  if (IsDeadlineThreadEligible(now)) {
    return DequeueDeadlineThread(now);
  } else if (likely(!fair_run_queue_.is_empty())) {
    return DequeueFairThread();
  } else {
    return &percpu::Get(this_cpu()).idle_thread;
  }
}