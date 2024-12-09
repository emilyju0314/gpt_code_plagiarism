TEST(ParsedCookieTest, InvalidTooLong) {
  std::string maxstr;
  maxstr.resize(ParsedCookie::kMaxCookieSize, 'a');

  ParsedCookie pc1(maxstr);
  EXPECT_TRUE(pc1.IsValid());

  ParsedCookie pc2(maxstr + "A");
  EXPECT_FALSE(pc2.IsValid());
}