int Mutex::RunSemop(bool wait, bool undo, int wait_time) {
  sembuf operation;
  operation.sem_num = static_cast<short>(sem_num_);
  operation.sem_flg = undo ? SEM_UNDO : 0;
  operation.sem_op = wait ? -1 : 1;

  int result = -1;
  if (wait_time < 0) {
    result = semop(sem_id_, &operation, 1);
  } else if (wait_time == 0) {
    operation.sem_flg |= IPC_NOWAIT;
    result = semop(sem_id_, &operation, 1);
  } else {
#if defined(__linux__)
    timespec timeout;
    timeout.tv_sec = wait_time / 1000;
    timeout.tv_nsec = (wait_time % 1000) * 1000000;
    result = semtimedop(sem_id_, &operation, 1, &timeout);
#elif defined(__unix__)
    result = semop(sem_id_, &operation, 1);
#endif
  }

  return result == 0 ? 0 : errno;
}