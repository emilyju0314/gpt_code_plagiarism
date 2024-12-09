TYPED_TEST(FunctionMockerTest, MocksFunctionsConstFunctionWithCallType) {
  EXPECT_CALL(Const(this->mock_foo_), CTConst(_)).WillOnce(Return('a'));

  EXPECT_EQ('a', Const(*this->foo_).CTConst(0));
}