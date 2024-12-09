TEST(UdpSocketWrapper, CreateSocket) {
  int32_t id = 42;
  // We can't test deletion of sockets without a socket manager.
  uint8_t threads = 1;
  UdpSocketManager* mgr = UdpSocketManager::Create(id, threads);
  UdpSocketWrapper* socket =
      UdpSocketWrapper::CreateSocket(id,
                                     mgr,
                                     NULL,  // CallbackObj
                                     NULL,  // IncomingSocketCallback
                                     false,  // ipV6Enable
                                     false);  // disableGQOS
  socket->CloseBlocking();
  UdpSocketManager::Return();
}