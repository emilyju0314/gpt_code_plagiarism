TEST_F(TCPSocketTest, AcceptForAdoptedUnconnectedSocket) {
  SocketDescriptor existing_socket =
      CreatePlatformSocket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  ASSERT_THAT(socket_.AdoptUnconnectedSocket(existing_socket), IsOk());

  IPEndPoint address(IPAddress::IPv4Localhost(), 0);
  SockaddrStorage storage;
  ASSERT_TRUE(address.ToSockAddr(storage.addr, &storage.addr_len));
  ASSERT_EQ(0, bind(existing_socket, storage.addr, storage.addr_len));

  ASSERT_THAT(socket_.Listen(kListenBacklog), IsOk());
  ASSERT_THAT(socket_.GetLocalAddress(&local_address_), IsOk());

  TestAcceptAsync();
}