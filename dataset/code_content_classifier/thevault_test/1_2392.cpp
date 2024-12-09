void run_thread(std::atomic<bool> &signal, std::string const &hostname, int const rank,
                size_t const simple_thread_id) {
  while (!signal) {
  }
  unsigned const num_cpu = std::thread::hardware_concurrency();
  std::string cpuset = rtt_c4::cpuset_to_string(num_cpu);
  std::cout << hostname << " :: Rank " << std::setfill('0') << std::setw(5) << rank << ", Thread "
            << std::setfill('0') << std::setw(3) << simple_thread_id
            << ", core affinity = " << cpuset << std::endl;
  return;
}