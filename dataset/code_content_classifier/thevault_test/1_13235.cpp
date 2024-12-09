TEST(Target, ForwardDependentConfigsFromGroups) {
  TestWithScope setup;

  Target a(setup.settings(), Label(SourceDir("//foo/"), "a"));
  a.set_output_type(Target::EXECUTABLE);
  a.SetToolchain(setup.toolchain());
  Target b(setup.settings(), Label(SourceDir("//foo/"), "b"));
  b.set_output_type(Target::GROUP);
  b.SetToolchain(setup.toolchain());
  Target c(setup.settings(), Label(SourceDir("//foo/"), "c"));
  c.set_output_type(Target::STATIC_LIBRARY);
  c.SetToolchain(setup.toolchain());
  a.deps().push_back(LabelTargetPair(&b));
  b.deps().push_back(LabelTargetPair(&c));

  // Direct dependent config on C.
  Config direct(setup.settings(), Label(SourceDir("//foo/"), "direct"));
  c.direct_dependent_configs().push_back(LabelConfigPair(&direct));

  // A forwards the dependent configs from B.
  a.forward_dependent_configs().push_back(LabelTargetPair(&b));

  c.OnResolved();
  b.OnResolved();
  a.OnResolved();

  // The config should now be on A, and in A's direct dependent configs.
  ASSERT_EQ(1u, a.configs().size());
  ASSERT_EQ(&direct, a.configs()[0].ptr);
  ASSERT_EQ(1u, a.direct_dependent_configs().size());
  ASSERT_EQ(&direct, a.direct_dependent_configs()[0].ptr);
}