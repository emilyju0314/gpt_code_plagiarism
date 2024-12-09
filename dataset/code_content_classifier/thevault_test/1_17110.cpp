TEST(StructuredHeaderTest, SH09HighPrecisionFloats) {
  // These values are exactly representable in binary floating point, so no
  // accuracy issues are expected in this test.
  base::Optional<ListOfLists> result =
      ParseListOfLists("1.03125;-1.03125;12345678901234.5;-12345678901234.5");
  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(*result,
            (ListOfLists{{Item(1.03125), Item(-1.03125), Item(12345678901234.5),
                          Item(-12345678901234.5)}}));

  result = ParseListOfLists("123456789012345.0");
  EXPECT_FALSE(result.has_value());

  result = ParseListOfLists("-123456789012345.0");
  EXPECT_FALSE(result.has_value());
}