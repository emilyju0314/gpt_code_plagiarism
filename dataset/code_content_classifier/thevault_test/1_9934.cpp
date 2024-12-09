TYPED_TEST(FunctionMockerTest, MocksDecimalFunction) {
  EXPECT_CALL(this->mock_foo_,
              Decimal(true, 'a', 0, 0, 1L, A<float>(), Lt(100), 5U, NULL, "hi"))
      .WillOnce(Return(5));

  EXPECT_EQ(5, this->foo_->Decimal(true, 'a', 0, 0, 1, 0, 0, 5, nullptr, "hi"));
}