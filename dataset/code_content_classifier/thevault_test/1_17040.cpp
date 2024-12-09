TEST_F(ScopedServiceBindingTest, ConnectDebugService) {
  // Remove the public service binding.
  service_binding_.reset();

  // Publish the test service to the "debug" directory.
  ScopedServiceBinding<testfidl::TestInterface> debug_service_binding(
      outgoing_directory_->debug_dir(), &test_service_);

  auto debug_stub =
      debug_service_directory_->Connect<testfidl::TestInterface>();
  VerifyTestInterface(&debug_stub, ZX_OK);

  auto release_stub =
      public_service_directory_->Connect<testfidl::TestInterface>();
  VerifyTestInterface(&release_stub, ZX_ERR_PEER_CLOSED);
}