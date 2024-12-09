void SwitchesStatesNamesVisitor::Visit(uint64_t /*event_timestamp*/,
                                       const ExitPerfEventData& event_data) {
  pid_t pid = event_data.pid;
  pid_t tid = event_data.tid;
  tid_to_pid_association_.insert_or_assign(tid, pid);
  // Don't log an error on overwrite, as it's expected that the pid was already known.
}