TYPED_TEST(FunctionMockerTest, MocksFunctionsOverloadedOnArgumentNumber) {
  EXPECT_CALL(this->mock_foo_, OverloadedOnArgumentNumber())
      .WillOnce(Return(1));
  EXPECT_CALL(this->mock_foo_, OverloadedOnArgumentNumber(_))
      .WillOnce(Return(2));

  EXPECT_EQ(2, this->foo_->OverloadedOnArgumentNumber(1));
  EXPECT_EQ(1, this->foo_->OverloadedOnArgumentNumber());
}