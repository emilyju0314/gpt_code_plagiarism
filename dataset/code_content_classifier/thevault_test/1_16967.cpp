TEST_F(TCPSocketTest, CancelPendingReadIfReady) {
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
  EXPECT_EQ(ERR_IO_PENDING, connecting_socket->ReadIfReady(
                                read_buffer.get(), read_buffer->size(),
                                read_callback.callback()));

  // Now cancel the pending ReadIfReady().
  connecting_socket->CancelReadIfReady();

  // Send data to |connecting_socket|.
  const char kMsg[] = "hello!";
  scoped_refptr<StringIOBuffer> write_buffer =
      base::MakeRefCounted<StringIOBuffer>(kMsg);

  TestCompletionCallback write_callback;
  int write_result = accepted_socket->Write(write_buffer.get(), strlen(kMsg),
                                            write_callback.callback(),
                                            TRAFFIC_ANNOTATION_FOR_TESTS);
  const int msg_size = strlen(kMsg);
  ASSERT_EQ(msg_size, write_result);

  TestCompletionCallback read_callback2;
  int read_result = connecting_socket->ReadIfReady(
      read_buffer.get(), read_buffer->size(), read_callback2.callback());
  if (read_result == ERR_IO_PENDING) {
    ASSERT_EQ(OK, read_callback2.GetResult(read_result));
    read_result = connecting_socket->ReadIfReady(
        read_buffer.get(), read_buffer->size(), read_callback2.callback());
  }

  ASSERT_EQ(msg_size, read_result);
  ASSERT_EQ(0, memcmp(&kMsg, read_buffer->data(), msg_size));
}