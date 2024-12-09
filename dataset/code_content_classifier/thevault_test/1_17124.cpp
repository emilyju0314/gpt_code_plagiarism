TEST(JSONReaderTest, InvalidSanity) {
  const char* const kInvalidJson[] = {
      "/* test *", "{\"foo\"", "{\"foo\":", "  [", "\"\\u123g\"", "{\n\"eh:\n}",
  };

  for (size_t i = 0; i < base::size(kInvalidJson); ++i) {
    LOG(INFO) << "Sanity test " << i << ": <" << kInvalidJson[i] << ">";
    JSONReader::ValueWithError root =
        JSONReader::ReadAndReturnValueWithError(kInvalidJson[i]);
    EXPECT_FALSE(root.value);
    EXPECT_NE("", root.error_message);
  }
}