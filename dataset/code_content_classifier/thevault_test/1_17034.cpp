TEST_F(ScopedServiceBindingTest, ConnectTwice) {
  auto stub = public_service_directory_->Connect<testfidl::TestInterface>();
  auto stub2 = public_service_directory_->Connect<testfidl::TestInterface>();
  VerifyTestInterface(&stub, ZX_OK);
  VerifyTestInterface(&stub2, ZX_OK);
}