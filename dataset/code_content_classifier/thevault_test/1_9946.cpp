TYPED_TEST(TemplateMockTest, Works) {
  TypeParam mock;

  EXPECT_CALL(mock, GetSize())
      .WillOnce(Return(0))
      .WillOnce(Return(1))
      .WillOnce(Return(0));
  EXPECT_CALL(mock, Push(_));
  int n = 5;
  EXPECT_CALL(mock, GetTop())
      .WillOnce(ReturnRef(n));
  EXPECT_CALL(mock, Pop())
      .Times(AnyNumber());

  EXPECT_EQ(0, mock.GetSize());
  mock.Push(5);
  EXPECT_EQ(1, mock.GetSize());
  EXPECT_EQ(5, mock.GetTop());
  mock.Pop();
  EXPECT_EQ(0, mock.GetSize());
}