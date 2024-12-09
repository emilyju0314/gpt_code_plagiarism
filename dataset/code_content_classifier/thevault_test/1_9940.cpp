TYPED_TEST(FunctionMockerTest, MocksFunctionsOverloadedOnConstnessOfThis) {
  EXPECT_CALL(this->mock_foo_, OverloadedOnConstness());
  EXPECT_CALL(Const(this->mock_foo_), OverloadedOnConstness())
      .WillOnce(Return('a'));

  EXPECT_EQ(0, this->foo_->OverloadedOnConstness());
  EXPECT_EQ('a', Const(*this->foo_).OverloadedOnConstness());
}