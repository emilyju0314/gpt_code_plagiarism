TEST_F(TCPSocketTest, DestroyWithPendingWrite) {
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

  // Repeatedly write to the socket until an operation does not complete
  // synchronously.
  base::RunLoop run_loop;
  scoped_refptr<IOBufferWithDestructionCallback> write_buffer(
      base::MakeRefCounted<IOBufferWithDestructionCallback>(
          run_loop.QuitClosure()));
  memset(write_buffer->data(), '1', write_buffer->size());
  TestCompletionCallback write_callback;
  while (true) {
    int result = connecting_socket->Write(
        write_buffer.get(), write_buffer->size(), write_callback.callback(),
        TRAFFIC_ANNOTATION_FOR_TESTS);
    if (result == ERR_IO_PENDING)
      break;
    ASSERT_LT(0, result);
  }

  // Release the handle to the read buffer and destroy the socket. Make sure the
  // write buffer is destroyed.
  write_buffer = nullptr;
  connecting_socket.reset();
  run_loop.Run();
}