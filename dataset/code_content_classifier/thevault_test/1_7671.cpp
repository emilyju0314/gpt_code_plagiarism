TEST(TestSchema, TestDecodeKeys_InvalidKeys) {
  Schema schema({ ColumnSchema("col1", STRING),
                  ColumnSchema("col2", UINT32),
                  ColumnSchema("col3", STRING) },
                2);

  EXPECT_EQ("<invalid key: Invalid argument: Error decoding composite key component"
            " 'col1': Missing separator after composite key string component: foo>",
            schema.DebugEncodedRowKey(Slice("foo"), Schema::START_KEY));
  EXPECT_EQ("<invalid key: Invalid argument: Error decoding composite key component 'col2': "
            "key too short>",
            schema.DebugEncodedRowKey(Slice("foo\x00\x00", 5), Schema::START_KEY));
  EXPECT_EQ("<invalid key: Invalid argument: Error decoding composite key component 'col2': "
            "key too short: FFFF>",
            schema.DebugEncodedRowKey(Slice("foo\x00\x00\xff\xff", 7), Schema::START_KEY));
}