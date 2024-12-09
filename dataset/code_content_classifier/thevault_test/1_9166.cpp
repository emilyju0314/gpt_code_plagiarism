TEST(Scale, DecodeOptionalBoolSuccess) {
  auto bytes = ByteArray{0, 1, 2, 1};
  using optbool = boost::optional<bool>;

  EXPECT_OUTCOME_TRUE(res, decode<FourOptBools>(bytes))
  ASSERT_EQ(res.b1, boost::none);
  ASSERT_EQ(res.b2, optbool(false));
  ASSERT_EQ(res.b3, optbool(true));
  ASSERT_EQ(res.b4 , optbool(false));
}