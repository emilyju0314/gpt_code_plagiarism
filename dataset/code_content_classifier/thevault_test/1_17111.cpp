TEST(StructuredHeaderTest, SerializeItem) {
  for (const auto& c : item_test_cases) {
    SCOPED_TRACE(c.name);
    if (c.expected) {
      base::Optional<std::string> result = SerializeItem(*c.expected);
      EXPECT_TRUE(result.has_value());
      EXPECT_EQ(result.value(), std::string(c.canonical ? c.canonical : c.raw));
    }
  }
}