TEST_F(ScopedServiceBindingTest, ConnectTwiceNewName) {
  const char kInterfaceName[] = "fuchsia.TestInterface2";

  ScopedServiceBinding<testfidl::TestInterface> new_service_binding(
      outgoing_directory_.get(), &test_service_, kInterfaceName);

  testfidl::TestInterfacePtr stub, stub2;
  public_service_directory_->Connect(
       kInterfaceName, stub.NewRequest().TakeChannel());
  public_service_directory_->Connect(
       kInterfaceName, stub2.NewRequest().TakeChannel());
  VerifyTestInterface(&stub, ZX_OK);
  VerifyTestInterface(&stub2, ZX_OK);
}