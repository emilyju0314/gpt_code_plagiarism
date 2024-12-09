TEST_F(ScopedServiceBindingTest, ConnectOnce_OnlyFirstConnectionSucceeds) {
  // Teardown the default multi-client binding and create a connect-once one.
  service_binding_ = nullptr;
  ScopedSingleClientServiceBinding<testfidl::TestInterface,
                                   ScopedServiceBindingPolicy::kConnectOnce>
      binding(outgoing_directory_.get(), &test_service_);

  // Connect the first client, and verify that it is functional.
  auto existing_client =
      public_service_directory_->Connect<testfidl::TestInterface>();
  VerifyTestInterface(&existing_client, ZX_OK);

  // Connect the second client, then verify that it gets closed and the existing
  // one remains functional.
  auto new_client =
      public_service_directory_->Connect<testfidl::TestInterface>();
  RunLoop().RunUntilIdle();
  EXPECT_FALSE(new_client);
  VerifyTestInterface(&existing_client, ZX_OK);

  // Disconnect the first client.
  existing_client.Unbind().TakeChannel().reset();
  RunLoop().RunUntilIdle();

  // Re-connect the second client, then verify that it gets closed.
  new_client = public_service_directory_->Connect<testfidl::TestInterface>();
  RunLoop().RunUntilIdle();
  EXPECT_FALSE(new_client);
}