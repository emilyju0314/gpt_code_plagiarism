void expect_ranges_eq(const std::vector<float> &a, const std::vector<float> &b) {
  for( int i=0; i<10; i++) {
    if(std::isnan(a[i])) {
      EXPECT_TRUE(std::isnan(b[i]));
    }
    else {
      EXPECT_NEAR(a[i], b[i], 1e-6);
    }
  }
}