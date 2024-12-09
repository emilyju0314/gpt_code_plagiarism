TEST(HashtableCommonTest, HashMunging) {
  const Hasher hasher;

  // We don't munge the hash value on non-pointer template types.
  {
    const sparsehash_internal::sh_hashtable_settings<int, Hasher, size_t, 1>
        settings(hasher, 0.0, 0.0);
    const int v = 1000;
    EXPECT_EQ(hasher(v), settings.hash(v));
  }

  {
    // We do munge the hash value on pointer template types.
    const sparsehash_internal::sh_hashtable_settings<int*, Hasher, size_t, 1>
        settings(hasher, 0.0, 0.0);
    int* v = NULL;
    v += 0x10000;  // get a non-trivial pointer value
    EXPECT_NE(hasher(v), settings.hash(v));
  }
  {
    const sparsehash_internal::sh_hashtable_settings<const int*, Hasher, size_t,
                                                     1> settings(hasher, 0.0,
                                                                 0.0);
    const int* v = NULL;
    v += 0x10000;  // get a non-trivial pointer value
    EXPECT_NE(hasher(v), settings.hash(v));
  }
}