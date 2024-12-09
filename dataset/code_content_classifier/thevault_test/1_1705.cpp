Mutex::MutexResult Mutex::Wait(int wait_ms) {
  if (event_ == NULL) return MUTEX_INVALID;

  DWORD result = WaitForSingleObject(event_, wait_ms < 0 ? INFINITE : wait_ms);
  if (result == WAIT_OBJECT_0 ||
    (allow_multi_post_ && result == WAIT_ABANDONED)) {
    return MUTEX_OK;
  }

  if (result == WAIT_TIMEOUT) {
    return MUTEX_TIMEOUT;
  } else {
    return GetLastError() == ERROR_INVALID_HANDLE ? MUTEX_INVALID : MUTEX_ERROR;
  }
}