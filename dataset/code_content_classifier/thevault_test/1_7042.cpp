int create_client_socket(struct sockaddr_storage *listenaddr,
                         socklen_t listenaddr_len, struct addrinfo *res) {
  int csock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (!WVPASS(csock >= 0)) {
    perror("client socket");
    return -1;
  }
  if (!WVPASS(!connect(csock, (struct sockaddr *)listenaddr, listenaddr_len))) {
    perror("connect");
    return -1;
  }
  struct sockaddr_in6 caddr;
  socklen_t caddr_len = sizeof(caddr);
  memset(&caddr, 0, caddr_len);
  if (!WVPASS(!getsockname(csock, (struct sockaddr *)&caddr, &caddr_len))) {
    perror("getsockname");
    return -1;
  }
  char buf[128];
  inet_ntop(AF_INET6, (struct sockaddr *)&caddr, buf, sizeof(buf));
  printf("Created client connection on %s:%d\n", buf, ntohs(caddr.sin6_port));
  return csock;
}