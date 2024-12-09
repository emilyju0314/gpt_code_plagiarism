TEST_F(HeapTest, DoublePtrTest) {
  DoublePtr ptr1;
  DoublePtr ptr2;
  ptr1.Connect(&ptr2);
  // Check that the correct copy constructor is used.
  DoublePtr ptr3(ptr1);
  EXPECT_EQ(&ptr3, ptr3.OtherEnd()->OtherEnd());
  EXPECT_TRUE(ptr1.OtherEnd() == nullptr);
  // Check that the correct operator= is used.
  ptr1 = ptr3;
  EXPECT_EQ(&ptr1, ptr1.OtherEnd()->OtherEnd());
  EXPECT_TRUE(ptr3.OtherEnd() == nullptr);
}