TYPED_TEST(FunctionMockerTest, MocksFunctionWithNonConstReferenceArgument) {
  int a = 0;
  EXPECT_CALL(this->mock_foo_, TakesNonConstReference(Ref(a)))
      .WillOnce(Return(true));

  EXPECT_TRUE(this->foo_->TakesNonConstReference(a));
}