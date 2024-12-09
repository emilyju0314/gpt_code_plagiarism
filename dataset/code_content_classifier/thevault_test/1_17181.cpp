TEST(RefCountedVec, EraseBeginEnd) {
  for (int len = 1; len < 20; ++len) {
    for (int erase_begin = 0; erase_begin < len; ++erase_begin) {
      for (int erase_end = erase_begin; erase_end <= len; ++erase_end) {
        std::vector<int> counts(len, 0);
        RefCountedVec v;
        for (int i = 0; i < len; ++i) {
          v.push_back(RefCounted(i, &counts[i]));
        }

        int erase_len = erase_end - erase_begin;

        v.erase(v.begin() + erase_begin, v.begin() + erase_end);

        EXPECT_EQ(len - erase_len, v.size());

        // Check the elements before the first element erased.
        for (int i = 0; i < erase_begin; ++i) {
          EXPECT_EQ(i, v[i].value_);
        }

        // Check the elements after the first element erased.
        for (int i = erase_begin; i < v.size(); ++i) {
          EXPECT_EQ(i + erase_len, v[i].value_);
        }

        // Check that the elements at the beginning are preserved.
        for (int i = 0; i < erase_begin; ++i) {
          EXPECT_EQ(1, counts[i]);
        }

        // Check that the erased elements are destroyed
        for (int i = erase_begin; i < erase_end; ++i) {
          EXPECT_EQ(0, counts[i]);
        }

        // Check that the elements at the end are preserved.
        for (int i = erase_end; i < len; ++i) {
          EXPECT_EQ(1, counts[i]);
        }
      }
    }
  }
}