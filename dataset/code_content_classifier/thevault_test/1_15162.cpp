void print_traffic(TrafficMonitor& monitor, int interval)
{
  auto begin = std::chrono::high_resolution_clock::now();
  while(true)
  {
    system("clear");
    monitor.print_packets_received_traffic();
    monitor.print_packets_provided_traffic();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::chrono::duration<double, std::milli> difference = std::chrono::high_resolution_clock::now() - begin;
    if (difference.count() > interval)
      break;
  }
}