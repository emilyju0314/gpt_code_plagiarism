TEST(Scale, encodeCollectionOf80) {
  // 80 items of value 1
  ByteArray collection(80, 1);
  auto match = ByteArray{65, 1};  // header
  match.insert(match.end(), collection.begin(), collection.end());
  ScaleEncoderStream s;
  ASSERT_NO_THROW((s << collection));
  auto &&out = s.data();
  ASSERT_EQ(out.size(), 82);
  ASSERT_EQ(out, match);
}