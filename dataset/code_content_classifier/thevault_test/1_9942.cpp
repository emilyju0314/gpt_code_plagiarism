TYPED_TEST(FunctionMockerTest, MocksUnaryFunctionWithCallType) {
  EXPECT_CALL(this->mock_foo_, CTUnary(Eq(2)))
      .Times(2)
      .WillOnce(Return(true))
      .WillOnce(Return(false));

  EXPECT_TRUE(this->foo_->CTUnary(2));
  EXPECT_FALSE(this->foo_->CTUnary(2));
}