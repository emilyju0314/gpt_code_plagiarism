Mutex::MutexResult Mutex::Post() {
  if (sem_id_ == -1) return MUTEX_INVALID;

  if (allow_multi_post_) {
    int arg = 1;
    int result = semctl(sem_id_, sem_num_, SETVAL, arg);
    return ErrnoToMutexResult(result == -1 ? errno : 0);
  } else {
    int result = RunSemop(false, true, 0);
    return ErrnoToMutexResult(result);
  }
}