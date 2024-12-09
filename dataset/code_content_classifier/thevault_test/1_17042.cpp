TEST_F(MultiUseBindingTest, MultipleLastClientCallback) {
  // Connect a client, verify it is functional.
  auto stub = public_service_directory_->Connect<testfidl::TestInterface>();
  VerifyTestInterface(&stub, ZX_OK);

  // Disconnect the client, the callback should have been called once.
  stub.Unbind().TakeChannel().reset();
  RunLoop().RunUntilIdle();
  EXPECT_EQ(disconnect_count_, 1);

  // Re-connect the client, verify it is functional.
  stub = public_service_directory_->Connect<testfidl::TestInterface>();
  VerifyTestInterface(&stub, ZX_OK);

  // Disconnect the client, the callback should have been called a second time.
  stub.Unbind().TakeChannel().reset();
  RunLoop().RunUntilIdle();
  EXPECT_EQ(disconnect_count_, 2);
}