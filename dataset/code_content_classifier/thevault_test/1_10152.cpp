TEST(UdpSocketManager, UnremovedSocketsGetCollectedAtManagerDeletion) {
#if defined(_WIN32)
  // It's hard to test an infinite wait, so we don't.
#else
  int32_t id = 42;
  uint8_t threads = 1;
  UdpSocketManager* mgr = UdpSocketManager::Create(id, threads);
  UdpSocketWrapper* unused_socket = UdpSocketWrapper::CreateSocket(
      id,
      mgr,
      NULL,  // CallbackObj
      NULL,  // IncomingSocketCallback
      false,  // ipV6Enable
      false);  // disableGQOS
  // The constructor will do AddSocket on the manager.
  // Call a member funtion to work around "set but not used" compliation
  // error on ChromeOS ARM.
  unused_socket->SetEventToNull();
  unused_socket = NULL;
  UdpSocketManager::Return();
#endif
}