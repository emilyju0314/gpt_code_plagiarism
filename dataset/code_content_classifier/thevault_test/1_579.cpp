void __broadcast(int fd, const std::vector<struct sockaddr_in>& neighbors,
    std::string msg) {
  for (auto neighbor : neighbors) {
    udpsend(fd, neighbor, msg);
  }
}