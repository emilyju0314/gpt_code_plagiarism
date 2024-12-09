static void ConstRefTest(const DoublePtr& ptr1) {
  DoublePtr ptr2(ptr1);  // Compiler error here.
  EXPECT_EQ(&ptr2, ptr2.OtherEnd()->OtherEnd());
  EXPECT_TRUE(ptr1.OtherEnd() == nullptr);
}