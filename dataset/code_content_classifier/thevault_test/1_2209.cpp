TEST_P(NetSocketTest, SocketPeekTest) {
  int socketType = GetParam();
  struct sockaddr_in addr = {};
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  socklen_t addrlen = sizeof(addr);
  int sendfd;
  int recvfd;
  ssize_t expectReadLen = 0;
  char sendbuf[8] = {};
  char recvbuf[2 * sizeof(sendbuf)] = {};
  ssize_t sendlen = sizeof(sendbuf);

  ASSERT_GE(sendfd = socket(AF_INET, socketType, 0), 0) << strerror(errno);
  // Setup the sender and receiver sockets.
  switch (socketType) {
    case SOCK_STREAM: {
      int acptfd;
      EXPECT_GE(acptfd = socket(AF_INET, socketType, 0), 0) << strerror(errno);
      EXPECT_EQ(bind(acptfd, reinterpret_cast<const struct sockaddr*>(&addr), sizeof(addr)), 0)
          << strerror(errno);
      EXPECT_EQ(getsockname(acptfd, reinterpret_cast<struct sockaddr*>(&addr), &addrlen), 0)
          << strerror(errno);
      EXPECT_EQ(addrlen, sizeof(addr));
      EXPECT_EQ(listen(acptfd, 1), 0) << strerror(errno);
      EXPECT_EQ(connect(sendfd, reinterpret_cast<const struct sockaddr*>(&addr), sizeof(addr)), 0)
          << strerror(errno);
      EXPECT_GE(recvfd = accept(acptfd, nullptr, nullptr), 0) << strerror(errno);
      EXPECT_EQ(close(acptfd), 0) << strerror(errno);
      // Expect to read both the packets in a single recv() call.
      expectReadLen = sizeof(recvbuf);
      break;
    }
    case SOCK_DGRAM: {
      EXPECT_GE(recvfd = socket(AF_INET, socketType, 0), 0) << strerror(errno);
      EXPECT_EQ(bind(recvfd, reinterpret_cast<const struct sockaddr*>(&addr), sizeof(addr)), 0)
          << strerror(errno);
      EXPECT_EQ(getsockname(recvfd, reinterpret_cast<struct sockaddr*>(&addr), &addrlen), 0)
          << strerror(errno);
      EXPECT_EQ(addrlen, sizeof(addr));
      // Expect to read single packet per recv() call.
      expectReadLen = sizeof(sendbuf);
      break;
    }
    default: {
      FAIL() << "unexpected test variant " << socketType;
    }
  }

  // This test sends 2 packets with known values and validates MSG_PEEK across the 2 packets.
  sendbuf[0] = 0xab;
  sendbuf[6] = 0xce;

  // send 2 separate packets and test peeking across
  EXPECT_EQ(sendto(sendfd, sendbuf, sizeof(sendbuf), 0,
                   reinterpret_cast<const struct sockaddr*>(&addr), addrlen),
            sendlen)
      << strerror(errno);
  EXPECT_EQ(sendto(sendfd, sendbuf, sizeof(sendbuf), 0,
                   reinterpret_cast<const struct sockaddr*>(&addr), addrlen),
            sendlen)
      << strerror(errno);

  auto expect_success_timeout = std::chrono::milliseconds(kTimeout);
  auto start = std::chrono::steady_clock::now();
  // First peek on first byte.
  EXPECT_EQ(asyncSocketRead(recvfd, sendfd, recvbuf, 1, MSG_PEEK, &addr, &addrlen, socketType,
                            expect_success_timeout),
            1);
  auto success_rcv_duration = std::chrono::steady_clock::now() - start;
  EXPECT_EQ(recvbuf[0], sendbuf[0]);

  // Second peek across first 2 packets and drain them from the socket receive queue.
  // Toggle the flags to MSG_PEEK every other iteration.
  ssize_t torecv = sizeof(recvbuf);
  for (int i = 0; torecv > 0; i++) {
    int flags = i % 2 ? 0 : MSG_PEEK;
    ssize_t readLen = 0;
    EXPECT_EQ(readLen = asyncSocketRead(recvfd, sendfd, recvbuf, sizeof(recvbuf), flags, &addr,
                                        &addrlen, socketType, expect_success_timeout),
              expectReadLen);
    if (HasFailure()) {
      break;
    }
    EXPECT_EQ(recvbuf[0], sendbuf[0]);
    EXPECT_EQ(recvbuf[6], sendbuf[6]);
    // For SOCK_STREAM, we validate peek across 2 packets with a single recv call.
    if (readLen == sizeof(recvbuf)) {
      EXPECT_EQ(recvbuf[8], sendbuf[0]);
      EXPECT_EQ(recvbuf[14], sendbuf[6]);
    }
    if (flags != MSG_PEEK) {
      torecv -= readLen;
    }
  }

  // Third peek on empty socket receive buffer, expect failure.
  //
  // As we expect failure, to keep the recv wait time minimal, we base it on the time taken for a
  // successful recv.
  EXPECT_EQ(asyncSocketRead(recvfd, sendfd, recvbuf, 1, MSG_PEEK, &addr, &addrlen, socketType,
                            success_rcv_duration * 10),
            0);
  EXPECT_EQ(close(recvfd), 0) << strerror(errno);
  EXPECT_EQ(close(sendfd), 0) << strerror(errno);
}