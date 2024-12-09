static int
poll_loop()
{
  if (server_fd > 0) {
    while (read_ready(server_fd) > 0) {
      accept_read(server_fd);
    }
  }
  pollfd pfd[POLL_GROUP_SIZE];
  int ip = 0;
  now    = ink_get_hrtime_internal();
  for (int i = 0; i <= last_fd; i++) {
    if (fd[i].fd > 0 && (!fd[i].ready || now >= fd[i].ready)) {
      pfd[ip].fd      = i;
      pfd[ip].events  = 0;
      pfd[ip].revents = 0;
      if (fd[i].read_cb) {
        pfd[ip].events |= POLLIN;
      }
      if (fd[i].write_cb) {
        pfd[ip].events |= POLLOUT;
      }
      ip++;
    }
    if (ip >= POLL_GROUP_SIZE || i == last_fd) {
      int n = poll(pfd, ip, POLL_TIMEOUT);
      if (n > 0) {
        for (int j = 0; j < ip; j++) {
          if (pfd[j].revents & (POLLIN | POLLERR | POLLHUP | POLLNVAL)) {
            if (verbose) {
              printf("poll read %d %X\n", pfd[j].fd, pfd[j].revents);
            }
            if (fd[pfd[j].fd].read_cb && fd[pfd[j].fd].read_cb(pfd[j].fd)) {
              fd[pfd[j].fd].close();
              continue;
            }
          }
          if (pfd[j].revents & (POLLOUT | POLLERR | POLLHUP | POLLNVAL)) {
            if (verbose) {
              printf("poll write %d %X\n", pfd[j].fd, pfd[j].revents);
            }
            if (fd[pfd[j].fd].write_cb && fd[pfd[j].fd].write_cb(pfd[j].fd)) {
              fd[pfd[j].fd].close();
              continue;
            }
          }
        }
      }
      ip = 0;
    }
  }
  return 0;
}