TEST_F(PreprocessorTests, ValuePassedIn) {
  std::set<std::string> defines;
  defines.insert("foo 1");
  bool result =
      fplbase::LoadFileWithDirectives("", &file_, defines, &error_message_);
  EXPECT_TRUE(result);
  EXPECT_EQ(file_, std::string("#define foo 1\n"));
}