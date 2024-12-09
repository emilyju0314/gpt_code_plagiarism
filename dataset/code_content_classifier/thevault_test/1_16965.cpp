TEST_F(TCPSocketTest, DestroyWithPendingRead) {
  ASSERT_NO_FATAL_FAILURE(SetUpListenIPv4());

  // Create a connected socket.

  TestCompletionCallback connect_callback;
  std::unique_ptr<TCPSocket> connecting_socket =
      std::make_unique<TCPSocket>(nullptr, nullptr, NetLogSource());
  int result = connecting_socket->Open(ADDRESS_FAMILY_IPV4);
  ASSERT_THAT(result, IsOk());
  int connect_result =
      connecting_socket->Connect(local_address_, connect_callback.callback());

  TestCompletionCallback accept_callback;
  std::unique_ptr<TCPSocket> accepted_socket;
  IPEndPoint accepted_address;
  result = socket_.Accept(&accepted_socket, &accepted_address,
                          accept_callback.callback());
  ASSERT_THAT(accept_callback.GetResult(result), IsOk());
  ASSERT_TRUE(accepted_socket.get());
  ASSERT_THAT(connect_callback.GetResult(connect_result), IsOk());

  // Try to read from the socket, but never write anything to the other end.
  base::RunLoop run_loop;
  scoped_refptr<IOBufferWithDestructionCallback> read_buffer(
      base::MakeRefCounted<IOBufferWithDestructionCallback>(
          run_loop.QuitClosure()));
  TestCompletionCallback read_callback;
  EXPECT_EQ(ERR_IO_PENDING,
            connecting_socket->Read(read_buffer.get(), read_buffer->size(),
                                    read_callback.callback()));

  // Release the handle to the read buffer and destroy the socket. Make sure the
  // read buffer is destroyed.
  read_buffer = nullptr;
  connecting_socket.reset();
  run_loop.Run();
}