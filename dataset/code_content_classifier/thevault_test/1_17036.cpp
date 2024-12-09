TEST_F(ScopedServiceBindingTest, SingleClientConnectNewName) {
  const char kInterfaceName[] = "fuchsia.TestInterface2";
  auto service_binding_new_name_ = std::make_unique<
      ScopedSingleClientServiceBinding<testfidl::TestInterface>>(
          outgoing_directory_.get(), &test_service_, kInterfaceName);

  testfidl::TestInterfacePtr stub;
  public_service_directory_->Connect(kInterfaceName,
                                     stub.NewRequest().TakeChannel());
  VerifyTestInterface(&stub, ZX_OK);
}