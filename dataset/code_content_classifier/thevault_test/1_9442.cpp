TEST_F(PreprocessorTests, MultipleDefinesPassedIn) {
  std::set<std::string> defines;
  defines.insert("foo");
  defines.insert("foo2");
  defines.insert("foo3");
  bool result =
      fplbase::LoadFileWithDirectives("", &file_, defines, &error_message_);
  EXPECT_TRUE(result);
  EXPECT_EQ(file_, std::string("#define foo\n#define foo2\n#define foo3\n"));
}