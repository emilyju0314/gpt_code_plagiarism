TYPED_TEST(FunctionMockerTest, MocksNullaryFunctionWithCallType) {
  EXPECT_CALL(this->mock_foo_, CTNullary())
      .WillOnce(Return(-1))
      .WillOnce(Return(0));

  EXPECT_EQ(-1, this->foo_->CTNullary());
  EXPECT_EQ(0, this->foo_->CTNullary());
}