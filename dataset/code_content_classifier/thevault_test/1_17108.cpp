TEST(StructuredHeaderTest, ParseItem) {
  for (const auto& c : parameterized_item_test_cases) {
    SCOPED_TRACE(c.name);
    base::Optional<ParameterizedItem> result = ParseItem(c.raw);
    EXPECT_EQ(result, c.expected);
  }
}