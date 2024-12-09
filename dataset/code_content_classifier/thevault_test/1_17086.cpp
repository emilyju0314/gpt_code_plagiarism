TEST(SocketTagTest, Compares) {
  SocketTag unset1;
  SocketTag unset2;

  EXPECT_TRUE(unset1 == unset2);
  EXPECT_FALSE(unset1 != unset2);
  EXPECT_FALSE(unset1 < unset2);

#if defined(OS_ANDROID)
  SocketTag s00(0, 0), s01(0, 1), s11(1, 1);

  EXPECT_FALSE(s00 == unset1);
  EXPECT_TRUE(s01 != unset2);
  EXPECT_FALSE(unset1 < s00);
  EXPECT_TRUE(s00 < unset2);

  EXPECT_FALSE(s00 == s01);
  EXPECT_FALSE(s01 == s11);
  EXPECT_FALSE(s00 == s11);
  EXPECT_TRUE(s00 < s01);
  EXPECT_TRUE(s01 < s11);
  EXPECT_TRUE(s00 < s11);
  EXPECT_FALSE(s01 < s00);
  EXPECT_FALSE(s11 < s01);
  EXPECT_FALSE(s11 < s00);
#endif
}