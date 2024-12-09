TEST_F(JavaObjectArrayReaderTest, RangeBasedFor) {
  JNIEnv* env = AttachCurrentThread();

  int i = 0;
  for (ScopedJavaLocalRef<jobject> element : array_.ReadElements<jobject>()) {
    EXPECT_SAME_OBJECT(element, array_members_[i++]);
  }
  EXPECT_EQ(i, array_len_);
}