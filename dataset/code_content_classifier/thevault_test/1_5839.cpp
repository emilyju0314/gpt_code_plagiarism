void KernelStackWatchdog::TLS::Data::SnapshotCopy(Data* copy) const {
  while (true) {
    Atomic32 v_0 = base::subtle::Acquire_Load(&seq_lock_);
    if (v_0 & 1) {
      // If the value is odd, then the thread is in the middle of modifying
      // its TLS, and we have to spin.
      base::subtle::PauseCPU();
      continue;
    }
    ANNOTATE_IGNORE_READS_BEGIN();
    memcpy(copy, this, sizeof(*copy));
    ANNOTATE_IGNORE_READS_END();
    Atomic32 v_1 = base::subtle::Release_Load(&seq_lock_);

    // If the value hasn't changed since we started the copy, then
    // we know that the copy was a consistent snapshot.
    if (v_1 == v_0) break;
  }
}