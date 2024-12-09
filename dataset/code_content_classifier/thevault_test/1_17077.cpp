MAYBE_TEST(ModuleCacheTest, UpdateNonNativeModulesPartitioning) {
  int destroyed_count = 0;
  const auto record_destroyed = [&destroyed_count]() { ++destroyed_count; };
  {
    ModuleCache cache;
    std::vector<std::unique_ptr<const ModuleCache::Module>> modules;
    modules.push_back(std::make_unique<FakeModule>(
        1, 1, false, BindLambdaForTesting(record_destroyed)));
    const ModuleCache::Module* module1 = modules.back().get();
    modules.push_back(std::make_unique<FakeModule>(
        2, 1, false, BindLambdaForTesting(record_destroyed)));
    cache.UpdateNonNativeModules({}, std::move(modules));
    cache.UpdateNonNativeModules({module1}, {});

    EXPECT_EQ(0, destroyed_count);
  }
  EXPECT_EQ(2, destroyed_count);
}