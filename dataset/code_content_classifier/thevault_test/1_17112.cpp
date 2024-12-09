TEST(StructuredHeaderTest, SerializeUnparseableDecimals) {
  struct UnparseableDecimal {
    const char* name;
    double value;
    const char* canonical;
  } float_test_cases[] = {
      {"negative 0", -0.0, "0.0"},
      {"0.0001", 0.0001, "0.0"},
      {"0.0000001", 0.0000001, "0.0"},
      {"1.0001", 1.0001, "1.0"},
      {"1.0009", 1.0009, "1.001"},
      {"round positive odd decimal", 0.0015, "0.002"},
      {"round positive even decimal", 0.0025, "0.002"},
      {"round negative odd decimal", -0.0015, "-0.002"},
      {"round negative even decimal", -0.0025, "-0.002"},
      {"round decimal up to integer part", 9.9995, "10.0"},
      {"subnormal numbers", std::numeric_limits<double>::denorm_min(), "0.0"},
      {"round up to 10 digits", 1e9 - 0.0000001, "1000000000.0"},
      {"round up to 11 digits", 1e10 - 0.000001, "10000000000.0"},
      {"round up to 12 digits", 1e11 - 0.00001, "100000000000.0"},
      {"largest serializable float", nextafter(1e12 - 0.0005, 0),
       "999999999999.999"},
      {"largest serializable negative float", -nextafter(1e12 - 0.0005, 0),
       "-999999999999.999"},
      // This will fail if we simply truncate the fractional portion.
      {"float rounds up to next int", 3.9999999, "4.0"},
      // This will fail if we first round to >3 digits, and then round again to
      // 3 digits.
      {"don't double round", 3.99949, "3.999"},
      // This will fail if we first round to 3 digits, and then round again to
      // max_avail_digits.
      {"don't double round", 123456789.99949, "123456789.999"},
  };
  for (const auto& test_case : float_test_cases) {
    SCOPED_TRACE(test_case.name);
    base::Optional<std::string> serialization =
        SerializeItem(Item(test_case.value));
    EXPECT_TRUE(serialization.has_value());
    EXPECT_EQ(*serialization, test_case.canonical);
  }
}