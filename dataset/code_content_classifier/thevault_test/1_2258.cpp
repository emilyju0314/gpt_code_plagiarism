void ThreadDispatcher::Exit() {
  canary_.Assert();

  LTRACE_ENTRY_OBJ;

  // only valid to call this on the current thread
  DEBUG_ASSERT(get_current_thread() == core_thread_);

  {
    Guard<fbl::Mutex> guard{get_lock()};

    SetStateLocked(ThreadState::Lifecycle::DYING);
  }

  // exit here
  // this will recurse back to us in ::Exiting()
  thread_exit(0);

  __UNREACHABLE;
}