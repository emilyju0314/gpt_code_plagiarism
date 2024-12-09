TEST_F(PreprocessorTests, DefineSameIdTwice) {
  const char* file =
      "#define foo\n"
      "#define foo";
  bool result = fplbase::LoadFileWithDirectives(file, &file_, kEmptyDefines,
                                                &error_message_);
  EXPECT_TRUE(result);
  EXPECT_EQ(file_, std::string(file));
}