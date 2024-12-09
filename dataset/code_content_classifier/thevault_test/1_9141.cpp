TEST_F(rocksdb_Open, OpenNonExistingDB) {
    rocksdb::Options options;
    options.create_if_missing = false;  // intentionally

    auto r = rocksdb::create(getPathString(), options);
    EXPECT_FALSE(r);
    EXPECT_EQ(r.error(), DatabaseError::INVALID_ARGUMENT);
  }