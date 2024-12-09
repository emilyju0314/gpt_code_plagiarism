TEST_F(MockPersistentNelStoreTest, FailedLoad) {
  MockPersistentNelStore store;
  MockPersistentNelStore::CommandList expected_commands;
  std::vector<NetworkErrorLoggingService::NelPolicy> loaded_policies;

  std::vector<NetworkErrorLoggingService::NelPolicy> prestored_policies = {
      nel_policy_};
  store.SetPrestoredPolicies(std::move(prestored_policies));
  EXPECT_EQ(1, store.StoredPoliciesCount());

  store.LoadNelPolicies(
      MakeExpectedRunNelPoliciesLoadedCallback(&loaded_policies));
  expected_commands.emplace_back(
      MockPersistentNelStore::Command::Type::LOAD_NEL_POLICIES);
  store.FinishLoading(false /* load_success */);
  // The pre-stored policy is not returned because loading failed.
  EXPECT_EQ(0u, loaded_policies.size());

  EXPECT_EQ(1u, store.GetAllCommands().size());
  EXPECT_TRUE(store.VerifyCommands(expected_commands));
}