static void *MainRemountTrigger(void *data) {
  char c;
  LogCvmfs(kLogCvmfs, kLogDebug, "starting remount trigger");
  while (true) {
    ReadPipe(pipe_remount_trigger_[0], &c, 1);
    if (c == 'Q')
      break;

    // We don't need to call this if we are already draining the caches
    if (!atomic_read32(&drainout_mode_)) {
      LogCvmfs(kLogCvmfs, kLogDebug, "trigger remount of idle mount point");
      RemountCheck();
    }
  }
  LogCvmfs(kLogCvmfs, kLogDebug, "stopping remount trigger");
  return NULL;
}