TEST(UdpSocketManager, AddAndRemoveSocketDoesNotLeakMemory) {
  int32_t id = 42;
  uint8_t threads = 1;
  UdpSocketManager* mgr = UdpSocketManager::Create(id, threads);
  UdpSocketWrapper* socket =
      UdpSocketWrapper::CreateSocket(id,
                                     mgr,
                                     NULL,  // CallbackObj
                                     NULL,  // IncomingSocketCallback
                                     false,  // ipV6Enable
                                     false);  // disableGQOS
  // The constructor will do AddSocket on the manager.
  // RemoveSocket indirectly calls Delete.
  EXPECT_EQ(true, mgr->RemoveSocket(socket));
  UdpSocketManager::Return();
}