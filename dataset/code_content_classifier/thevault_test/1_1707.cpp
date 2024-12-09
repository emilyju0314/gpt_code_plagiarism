Mutex::MutexResult Mutex::Wait(int wait_ms) {
  if (sem_id_ == -1) return MUTEX_INVALID;

  int result = RunSemop(true, !allow_multi_post_, wait_ms);
  return ErrnoToMutexResult(result);
}