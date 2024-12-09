double start_time() {
  struct timespec tp;
  clock_gettime(CLOCK_REALTIME, &tp);
  return 1e9*tp.tv_sec + tp.tv_nsec;
}