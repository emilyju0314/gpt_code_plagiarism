Mutex::MutexResult Mutex::Post() {
  if (event_ == NULL) return MUTEX_INVALID;

  if (SetEvent(event_)) {
    return MUTEX_OK;
  } else {
    return GetLastError() == ERROR_INVALID_HANDLE ? MUTEX_INVALID : MUTEX_ERROR;
  }
}