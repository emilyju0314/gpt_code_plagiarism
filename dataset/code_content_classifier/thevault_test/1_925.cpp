inline double
time_diff(rusage const& a, rusage const& b)
{
  double const sec = (a.ru_utime.tv_sec - b.ru_utime.tv_sec) +
                     (a.ru_stime.tv_sec - b.ru_stime.tv_sec);
  double const microsec = (a.ru_utime.tv_usec - b.ru_utime.tv_usec) +
                          (a.ru_stime.tv_usec - b.ru_stime.tv_usec);
  return sec + 1e-6 * microsec;
}