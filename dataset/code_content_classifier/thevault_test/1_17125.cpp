TEST(JSONReaderTest, ReplaceInvalidCharacters) {
  // U+D800 is a lone high surrogate.
  const std::string invalid_high = "\"\xED\xA0\x80\"";
  Optional<Value> value =
      JSONReader::Read(invalid_high, JSON_REPLACE_INVALID_CHARACTERS);
  ASSERT_TRUE(value);
  ASSERT_TRUE(value->is_string());
  // Expect three U+FFFD (one for each UTF-8 byte in the invalid code point).
  EXPECT_EQ("\xEF\xBF\xBD\xEF\xBF\xBD\xEF\xBF\xBD", value->GetString());

  // U+DFFF is a lone low surrogate.
  const std::string invalid_low = "\"\xED\xBF\xBF\"";
  value = JSONReader::Read(invalid_low, JSON_REPLACE_INVALID_CHARACTERS);
  ASSERT_TRUE(value);
  ASSERT_TRUE(value->is_string());
  // Expect three U+FFFD (one for each UTF-8 byte in the invalid code point).
  EXPECT_EQ("\xEF\xBF\xBD\xEF\xBF\xBD\xEF\xBF\xBD", value->GetString());
}