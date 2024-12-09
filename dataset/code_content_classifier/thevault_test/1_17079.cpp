MAYBE_TEST(ModuleCacheTest, NativeModuleOverAuxiliaryModuleProvider) {
  ModuleCache cache;

  MockModuleProvider auxiliary_provider(/*module_size=*/100);
  cache.RegisterAuxiliaryModuleProvider(&auxiliary_provider);

  const ModuleCache::Module* module =
      cache.GetModuleForAddress(reinterpret_cast<uintptr_t>(&AFunctionForTest));
  ASSERT_NE(nullptr, module);

  // The module should be a native module, which will have size greater than 100
  // bytes.
  EXPECT_NE(100u, module->GetSize());
  cache.UnregisterAuxiliaryModuleProvider(&auxiliary_provider);
}