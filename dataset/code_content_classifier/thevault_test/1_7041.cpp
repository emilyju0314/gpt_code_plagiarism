ResultsSet listen_for_responses(int s4, int s6)
{
  ResultsSet results;
  struct timeval tv;
  fd_set rfds;
  int maxfd = (s4 > s6) ? s4 : s6;

  memset(&tv, 0, sizeof(tv));
  tv.tv_sec = ssdp_timeout_secs;
  tv.tv_usec = 0;

  FD_ZERO(&rfds);
  FD_SET(s4, &rfds);
  FD_SET(s6, &rfds);

  while (select(maxfd + 1, &rfds, NULL, NULL, &tv) > 0) {
    if (FD_ISSET(s4, &rfds)) {
      std::string ip = handle_ssdp_response(s4, AF_INET);
      if (!ip.empty()) {
        results.insert(ip);
      }
    }
    if (FD_ISSET(s6, &rfds)) {
      std::string ip = handle_ssdp_response(s6, AF_INET6);
      if (!ip.empty()) {
        results.insert(ip);
      }
    }

    FD_ZERO(&rfds);
    FD_SET(s4, &rfds);
    FD_SET(s6, &rfds);
  }

  return results;
}