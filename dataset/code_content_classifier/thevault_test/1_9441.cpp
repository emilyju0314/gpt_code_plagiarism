TEST_F(PreprocessorTests, OneDefinePassedIn) {
  std::set<std::string> defines;
  defines.insert("foo");
  bool result =
      fplbase::LoadFileWithDirectives("", &file_, defines, &error_message_);
  EXPECT_TRUE(result);
  EXPECT_EQ(file_, std::string("#define foo\n"));
}