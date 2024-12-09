TEST_F(ScopedServiceBindingTest, SingleClientPreferNew) {
  // Teardown the default multi-client binding and create a prefer-new one.
  service_binding_ = nullptr;
  ScopedSingleClientServiceBinding<testfidl::TestInterface,
                                   ScopedServiceBindingPolicy::kPreferNew>
      binding(outgoing_directory_.get(), &test_service_);

  // Connect the first client, and verify that it is functional.
  auto existing_client =
      public_service_directory_->Connect<testfidl::TestInterface>();
  VerifyTestInterface(&existing_client, ZX_OK);

  // Connect the second client, so the existing one should be disconnected and
  // the new should be functional.
  auto new_client =
      public_service_directory_->Connect<testfidl::TestInterface>();
  RunLoop().RunUntilIdle();
  EXPECT_FALSE(existing_client);
  VerifyTestInterface(&new_client, ZX_OK);
}