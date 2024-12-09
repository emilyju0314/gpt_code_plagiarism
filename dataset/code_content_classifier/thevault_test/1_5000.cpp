TEST(ExtractRemoteCallArgumentsOrDie, Basic) {
  std::vector<Value> values;
  values.emplace_back(123);
  values.emplace_back("foo");

  int int_argument = 0;
  std::string string_argument;
  ExtractRemoteCallArgumentsOrDie(kSomeFunc, std::move(values), &int_argument,
                                  &string_argument);
  EXPECT_EQ(int_argument, 123);
  EXPECT_EQ(string_argument, "foo");
}