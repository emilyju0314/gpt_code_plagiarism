void TraceLog::FlushCurrentThread(int generation, bool discard_events) {
  {
    AutoLock lock(lock_);
    if (!CheckGeneration(generation) || !flush_task_runner_) {
      // This is late. The corresponding flush has finished.
      return;
    }
  }

  // This will flush the thread local buffer.
  delete thread_local_event_buffer_.Get();

  auto on_flush_override = on_flush_override_.load(std::memory_order_relaxed);
  if (on_flush_override) {
    on_flush_override();
  }

  // Scheduler uses TRACE_EVENT macros when posting a task, which can lead
  // to acquiring a tracing lock. Given that posting a task requires grabbing
  // a scheduler lock, we need to post this task outside tracing lock to avoid
  // deadlocks.
  scoped_refptr<SequencedTaskRunner> cached_flush_task_runner;
  {
    AutoLock lock(lock_);
    cached_flush_task_runner = flush_task_runner_;
    if (!CheckGeneration(generation) || !flush_task_runner_ ||
        !thread_task_runners_.empty())
      return;
  }
  cached_flush_task_runner->PostTask(
      FROM_HERE, BindOnce(&TraceLog::FinishFlush, Unretained(this), generation,
                          discard_events));
}