TEST_F(MockPersistentNelStoreTest, FinishLoading) {
  MockPersistentNelStore store;
  MockPersistentNelStore::CommandList expected_commands;
  std::vector<NetworkErrorLoggingService::NelPolicy> loaded_policies;

  store.LoadNelPolicies(
      MakeExpectedRunNelPoliciesLoadedCallback(&loaded_policies));
  expected_commands.emplace_back(
      MockPersistentNelStore::Command::Type::LOAD_NEL_POLICIES);

  store.FinishLoading(true /* load_success */);
  EXPECT_EQ(0u, loaded_policies.size());

  EXPECT_EQ(1u, store.GetAllCommands().size());
  EXPECT_TRUE(store.VerifyCommands(expected_commands));

  // Test should not crash because the callback has been run.
}