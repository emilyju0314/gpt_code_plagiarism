TYPED_TEST(FunctionMockerTest, MocksBinaryFunction) {
  EXPECT_CALL(this->mock_foo_, Binary(2, _)).WillOnce(Return(3));

  EXPECT_EQ(3, this->foo_->Binary(2, 1));
}