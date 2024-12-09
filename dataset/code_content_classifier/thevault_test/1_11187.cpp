TEST_F(BitVectorTest, SetAll) {
  // Test the default constructor and set/resetall.
  BitVector map(42);
  TestAll(map, false);
  map.SetAllTrue();
  TestAll(map, true);
  map.SetAllFalse();
  TestAll(map, false);
}