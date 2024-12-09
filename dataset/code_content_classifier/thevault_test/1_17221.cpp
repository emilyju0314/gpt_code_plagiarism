TEST_F(AndroidImageReaderTest, GetImageReaderInstance) {
  // It is expected that image reader support will be available from android
  // version OREO.
  EXPECT_EQ(AndroidImageReader::GetInstance().IsSupported(),
            base::android::BuildInfo::GetInstance()->sdk_int() >=
                base::android::SDK_VERSION_P);
}