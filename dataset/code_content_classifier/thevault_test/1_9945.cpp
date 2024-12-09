TYPED_TEST(ExpectCallTest, UnmentionedFunctionCanBeCalledAnyNumberOfTimes) {
  { TypeParam b; }

  {
    TypeParam b;
    b.DoB();
  }

  {
    TypeParam b;
    b.DoB();
    b.DoB();
  }
}