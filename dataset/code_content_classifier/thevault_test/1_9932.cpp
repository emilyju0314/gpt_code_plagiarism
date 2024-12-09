TYPED_TEST(FunctionMockerTest, MocksUnaryFunction) {
  EXPECT_CALL(this->mock_foo_, Unary(Eq(2))).Times(2).WillOnce(Return(true));

  EXPECT_TRUE(this->foo_->Unary(2));
  EXPECT_FALSE(this->foo_->Unary(2));
}