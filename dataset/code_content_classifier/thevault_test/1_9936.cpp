TYPED_TEST(FunctionMockerTest, MocksFunctionWithConstReferenceArgument) {
  int a = 0;
  EXPECT_CALL(this->mock_foo_, TakesConstReference(Ref(a)))
      .WillOnce(Return("Hello"));

  EXPECT_EQ("Hello", this->foo_->TakesConstReference(a));
}