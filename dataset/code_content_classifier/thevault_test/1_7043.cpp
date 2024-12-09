bool create_local_socketpair(struct sockaddr_storage *listenaddr,
                             socklen_t listenaddr_len, int *csock, int *ssock,
                             struct addrinfo **res) {
  struct addrinfo hints;

  // Get local interface information.
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET6;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_flags = AI_PASSIVE | AI_V4MAPPED;
  int err = getaddrinfo(NULL, "0", &hints, res);
  if (err != 0) {
    WVPASSEQ("Error from getaddrinfo: ", gai_strerror(err));
    return false;
  }

  *ssock = socket((*res)->ai_family, (*res)->ai_socktype, (*res)->ai_protocol);
  if (!WVPASS(*ssock >= 0)) {
    perror("server socket");
    return false;
  }

  if (!WVPASS(!bind(*ssock, (*res)->ai_addr, (*res)->ai_addrlen))) {
    perror("bind");
    return false;
  }

  // Figure out the local port we got.
  memset(listenaddr, 0, listenaddr_len);
  if (!WVPASS(!getsockname(*ssock, (struct sockaddr *)listenaddr,
                           &listenaddr_len))) {
    perror("getsockname");
    return false;
  }

  printf("Bound server socket to port=%d\n",
         listenaddr->ss_family == AF_INET
             ? ntohs(((struct sockaddr_in *)listenaddr)->sin_port)
             : ntohs(((struct sockaddr_in6 *)listenaddr)->sin6_port));

  *csock = create_client_socket(listenaddr, listenaddr_len, *res);
  if (*csock < 0) {
    return false;
  }
  return true;
}