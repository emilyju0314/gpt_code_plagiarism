zx_status_t ThreadDispatcher::Initialize() {
  LTRACE_ENTRY_OBJ;
  // Associate the proc's address space with this thread.
  process_->aspace()->AttachToThread(core_thread_);

  // Make sure we contribute a FutexState object to our process's futex state.
  auto result = process_->futex_context().GrowFutexStatePool();
  if (result != ZX_OK) {
    return result;
  }

  Guard<fbl::Mutex> guard{get_lock()};
  // we've entered the initialized state
  SetStateLocked(ThreadState::Lifecycle::INITIALIZED);
  return ZX_OK;
}