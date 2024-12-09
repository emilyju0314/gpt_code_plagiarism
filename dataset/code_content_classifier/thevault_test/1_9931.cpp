TYPED_TEST(FunctionMockerTest, MocksNullaryFunction) {
  EXPECT_CALL(this->mock_foo_, Nullary())
      .WillOnce(DoDefault())
      .WillOnce(Return(1));

  EXPECT_EQ(0, this->foo_->Nullary());
  EXPECT_EQ(1, this->foo_->Nullary());
}