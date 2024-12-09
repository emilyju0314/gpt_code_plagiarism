folly::Optional<double>
SystemMetrics::getCPUpercentage() {
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);

  ProcCpuTime nowCpuTime(usage);
  folly::Optional<double> cpuPct{folly::none};

  // calculate the CPU% = (process time diff) / (time elapsed) * 100
  if (prevCpuTime.timestamp != 0 && // has cached before
      nowCpuTime.timestamp > prevCpuTime.timestamp &&
      nowCpuTime.totalTime > prevCpuTime.totalTime) {
    uint64_t timestampDiff = nowCpuTime.timestamp - prevCpuTime.timestamp;
    uint64_t procTimeDiff = nowCpuTime.totalTime - prevCpuTime.totalTime;
    cpuPct = ((double)procTimeDiff / (double)timestampDiff) * 100;
  }

  // update the cache for next CPU% update
  prevCpuTime = nowCpuTime;

  return cpuPct;
}