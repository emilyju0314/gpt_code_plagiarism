TYPED_TEST(FunctionMockerTest, MocksFunctionWithConstArgument) {
  EXPECT_CALL(this->mock_foo_, TakesConst(Lt(10))).WillOnce(DoDefault());

  EXPECT_FALSE(this->foo_->TakesConst(5));
}