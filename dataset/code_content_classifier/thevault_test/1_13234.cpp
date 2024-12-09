TEST(Target, LibInheritance) {
  TestWithScope setup;

  const std::string lib("foo");
  const SourceDir libdir("/foo_dir/");

  // Leaf target with ldflags set.
  Target z(setup.settings(), Label(SourceDir("//foo/"), "z"));
  z.set_output_type(Target::STATIC_LIBRARY);
  z.config_values().libs().push_back(lib);
  z.config_values().lib_dirs().push_back(libdir);
  z.SetToolchain(setup.toolchain());
  z.OnResolved();

  // All lib[_dir]s should be set when target is resolved.
  ASSERT_EQ(1u, z.all_libs().size());
  EXPECT_EQ(lib, z.all_libs()[0]);
  ASSERT_EQ(1u, z.all_lib_dirs().size());
  EXPECT_EQ(libdir, z.all_lib_dirs()[0]);

  // Shared library target should inherit the libs from the static library
  // and its own. Its own flag should be before the inherited one.
  const std::string second_lib("bar");
  const SourceDir second_libdir("/bar_dir/");
  Target shared(setup.settings(), Label(SourceDir("//foo/"), "shared"));
  shared.set_output_type(Target::SHARED_LIBRARY);
  shared.config_values().libs().push_back(second_lib);
  shared.config_values().lib_dirs().push_back(second_libdir);
  shared.deps().push_back(LabelTargetPair(&z));
  shared.SetToolchain(setup.toolchain());
  shared.OnResolved();

  ASSERT_EQ(2u, shared.all_libs().size());
  EXPECT_EQ(second_lib, shared.all_libs()[0]);
  EXPECT_EQ(lib, shared.all_libs()[1]);
  ASSERT_EQ(2u, shared.all_lib_dirs().size());
  EXPECT_EQ(second_libdir, shared.all_lib_dirs()[0]);
  EXPECT_EQ(libdir, shared.all_lib_dirs()[1]);

  // Executable target shouldn't get either by depending on shared.
  Target exec(setup.settings(), Label(SourceDir("//foo/"), "exec"));
  exec.set_output_type(Target::EXECUTABLE);
  exec.deps().push_back(LabelTargetPair(&shared));
  exec.SetToolchain(setup.toolchain());
  exec.OnResolved();
  EXPECT_EQ(0u, exec.all_libs().size());
  EXPECT_EQ(0u, exec.all_lib_dirs().size());
}