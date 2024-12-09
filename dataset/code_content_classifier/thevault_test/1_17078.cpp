TEST(ModuleCacheTest, RegisterAuxiliaryModuleProvider) {
  ModuleCache cache;
  EXPECT_EQ(nullptr, cache.GetModuleForAddress(1));

  MockModuleProvider auxiliary_provider;
  cache.RegisterAuxiliaryModuleProvider(&auxiliary_provider);
  auto* module = cache.GetModuleForAddress(1);
  EXPECT_NE(nullptr, module);
  EXPECT_EQ(1U, module->GetBaseAddress());
  cache.UnregisterAuxiliaryModuleProvider(&auxiliary_provider);

  // Even when unregistered, the module remains in the cache.
  EXPECT_EQ(module, cache.GetModuleForAddress(1));
}