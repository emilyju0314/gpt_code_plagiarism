TEST_F(AndroidImageReaderTest, CompareImageReaderInstance) {
  AndroidImageReader& a1 = AndroidImageReader::GetInstance();
  AndroidImageReader& a2 = AndroidImageReader::GetInstance();
  ASSERT_EQ(&a1, &a2);
}