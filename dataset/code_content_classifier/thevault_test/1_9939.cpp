TYPED_TEST(FunctionMockerTest, MocksFunctionsOverloadedOnArgumentType) {
  EXPECT_CALL(this->mock_foo_, OverloadedOnArgumentType(An<int>()))
      .WillOnce(Return(1));
  EXPECT_CALL(this->mock_foo_, OverloadedOnArgumentType(TypedEq<char>('a')))
      .WillOnce(Return('b'));

  EXPECT_EQ(1, this->foo_->OverloadedOnArgumentType(0));
  EXPECT_EQ('b', this->foo_->OverloadedOnArgumentType('a'));
}