inline bool IsThreadAdjustable(const thread_t* thread) {
  // Checking the thread state avoids unnecessary adjustments on a thread that
  // is no longer competing.
  // TODO(eieio): Fix thread_is_idle to take a const pointer to the thread.
  return !thread_is_idle(const_cast<thread_t*>(thread)) && IsFairThread(thread) &&
         thread->state == THREAD_READY;
}