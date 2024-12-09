TEST(ValueEmscriptenValConversion, IntegerValueError) {
  {
    constexpr int64_t k64BitMax = std::numeric_limits<int64_t>::max();
    const optional<emscripten::val> converted =
        ConvertValueToEmscriptenVal(Value(k64BitMax));
    EXPECT_FALSE(converted);
  }

  {
    constexpr int64_t k64BitMin = std::numeric_limits<int64_t>::min();
    std::string error_message;
    const optional<emscripten::val> converted =
        ConvertValueToEmscriptenVal(Value(k64BitMin), &error_message);
    EXPECT_FALSE(converted);
    EXPECT_THAT(
        error_message,
        MatchesRegex("The integer -9223372036854775808 cannot be converted "
                     "into a floating-point double value without loss of "
                     "precision: it is outside .* range"));
  }
}