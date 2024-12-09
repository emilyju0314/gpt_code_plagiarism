TEST(Target, GroupDeps) {
  TestWithScope setup;

  // Two low-level targets.
  Target x(setup.settings(), Label(SourceDir("//component/"), "x"));
  x.set_output_type(Target::STATIC_LIBRARY);
  x.SetToolchain(setup.toolchain());
  x.OnResolved();
  Target y(setup.settings(), Label(SourceDir("//component/"), "y"));
  y.set_output_type(Target::STATIC_LIBRARY);
  y.SetToolchain(setup.toolchain());
  y.OnResolved();

  // Make a group for both x and y.
  Target g(setup.settings(), Label(SourceDir("//group/"), "g"));
  g.set_output_type(Target::GROUP);
  g.deps().push_back(LabelTargetPair(&x));
  g.deps().push_back(LabelTargetPair(&y));

  // Random placeholder target so we can see the group's deps get inserted at
  // the right place.
  Target b(setup.settings(), Label(SourceDir("//app/"), "b"));
  b.set_output_type(Target::STATIC_LIBRARY);
  b.SetToolchain(setup.toolchain());
  b.OnResolved();

  // Make a target depending on the group and "b". OnResolved will expand.
  Target a(setup.settings(), Label(SourceDir("//app/"), "a"));
  a.set_output_type(Target::EXECUTABLE);
  a.deps().push_back(LabelTargetPair(&g));
  a.deps().push_back(LabelTargetPair(&b));
  a.SetToolchain(setup.toolchain());
  a.OnResolved();

  // The group's deps should be inserted after the group itself in the deps
  // list, so we should get "g, x, y, b"
  ASSERT_EQ(4u, a.deps().size());
  EXPECT_EQ(&g, a.deps()[0].ptr);
  EXPECT_EQ(&x, a.deps()[1].ptr);
  EXPECT_EQ(&y, a.deps()[2].ptr);
  EXPECT_EQ(&b, a.deps()[3].ptr);
}