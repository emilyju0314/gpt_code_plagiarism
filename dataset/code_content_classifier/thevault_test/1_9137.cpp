TEST(ScaleCompactTest, EncodeOutOfRangeBigIntegerFails) {
  // try to encode out of range big integer value MAX_BIGINT + 1 == 2^536
  // too big value, even for big integer case
  // we are going to have kValueIsTooBig error
  CompactInteger v(
      "224945689727159819140526925384299092943484855915095831"
      "655037778630591879033574393515952034305194542857496045"
      "531676044756160413302774714984450425759043258192756736");  // 2^536

  ScaleEncoderStream out;
  ASSERT_ANY_THROW((out << v));     // value is too big, it is not encoded
  ASSERT_EQ(out.data().size(), 0);  // nothing was written to buffer
}