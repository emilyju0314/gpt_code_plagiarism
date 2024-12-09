TYPED_TEST(FunctionMockerTest, MocksDecimalFunctionWithCallType) {
  EXPECT_CALL(this->mock_foo_, CTDecimal(true, 'a', 0, 0, 1L, A<float>(),
                                         Lt(100), 5U, NULL, "hi"))
      .WillOnce(Return(10));

  EXPECT_EQ(10, this->foo_->CTDecimal(true, 'a', 0, 0, 1, 0, 0, 5, NULL, "hi"));
}