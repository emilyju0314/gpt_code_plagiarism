TEST(ModuleCacheTest, UnregisterAuxiliaryModuleProvider) {
  ModuleCache cache;

  EXPECT_EQ(nullptr, cache.GetModuleForAddress(1));

  MockModuleProvider auxiliary_provider;
  cache.RegisterAuxiliaryModuleProvider(&auxiliary_provider);
  cache.UnregisterAuxiliaryModuleProvider(&auxiliary_provider);

  EXPECT_EQ(nullptr, cache.GetModuleForAddress(1));
}