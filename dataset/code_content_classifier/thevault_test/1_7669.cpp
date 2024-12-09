TEST(TestSchema, TestProjectMissingColumn) {
  Schema schema1({ ColumnSchema("key", STRING), ColumnSchema("val", UINT32) }, 1);
  Schema schema2({ ColumnSchema("val", UINT32), ColumnSchema("non_present", STRING) }, 0);
  Schema schema3({ ColumnSchema("val", UINT32), ColumnSchema("non_present", UINT32, true) }, 0);

  RowProjector row_projector(&schema1, &schema2);
  Status s = row_projector.Init();
  ASSERT_TRUE(s.IsInvalidArgument());
  ASSERT_STR_CONTAINS(s.message().ToString(),
    "does not exist in the projection, and it does not have a nullable type");

  // Verify Default nullable column with no default value
  ASSERT_OK(row_projector.Reset(&schema1, &schema3));

  ASSERT_EQ(1, row_projector.base_cols_mapping().size());
  ASSERT_EQ(0, row_projector.adapter_cols_mapping().size());

  ASSERT_EQ(row_projector.base_cols_mapping()[0].first, 0);  // val schema2
  ASSERT_EQ(row_projector.base_cols_mapping()[0].second, 1); // val schema1
}