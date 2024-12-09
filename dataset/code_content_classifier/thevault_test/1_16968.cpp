TEST_F(TCPSocketTest, BeforeConnectCallback) {
  // A receive buffer size that is between max and minimum buffer size limits,
  // and weird enough to likely not be a default value.
  const int kReceiveBufferSize = 32 * 1024 + 1117;
  ASSERT_NO_FATAL_FAILURE(SetUpListenIPv4());

  TestCompletionCallback accept_callback;
  std::unique_ptr<TCPSocket> accepted_socket;
  IPEndPoint accepted_address;
  EXPECT_THAT(socket_.Accept(&accepted_socket, &accepted_address,
                             accept_callback.callback()),
              IsError(ERR_IO_PENDING));

  TestCompletionCallback connect_callback;
  TCPClientSocket connecting_socket(local_address_list(), nullptr, nullptr,
                                    nullptr, NetLogSource());

  connecting_socket.SetBeforeConnectCallback(base::BindLambdaForTesting([&] {
    EXPECT_FALSE(connecting_socket.IsConnected());
    int result = connecting_socket.SetReceiveBufferSize(kReceiveBufferSize);
    EXPECT_THAT(result, IsOk());
    return result;
  }));
  int connect_result = connecting_socket.Connect(connect_callback.callback());

  EXPECT_THAT(accept_callback.WaitForResult(), IsOk());
  EXPECT_THAT(connect_callback.GetResult(connect_result), IsOk());

  int actual_size = 0;
  socklen_t actual_size_len = sizeof(actual_size);
  int os_result = getsockopt(
      connecting_socket.SocketDescriptorForTesting(), SOL_SOCKET, SO_RCVBUF,
      reinterpret_cast<char*>(&actual_size), &actual_size_len);
  ASSERT_EQ(0, os_result);
// Linux platforms generally allocate twice as much buffer size is requested to
// account for internal kernel data structures.
#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
  EXPECT_EQ(2 * kReceiveBufferSize, actual_size);
// Unfortunately, Apple platform behavior doesn't seem to be documented, and
// doesn't match behavior on any other platforms.
// Fuchsia doesn't currently implement SO_RCVBUF.
#elif !defined(OS_APPLE) && !defined(OS_FUCHSIA)
  EXPECT_EQ(kReceiveBufferSize, actual_size);
#endif
}