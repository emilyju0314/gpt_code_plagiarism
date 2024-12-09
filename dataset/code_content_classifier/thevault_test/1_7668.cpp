TEST(TestSchema, TestSchema) {
  Schema empty_schema;
  ASSERT_GT(empty_schema.memory_footprint_excluding_this(), 0);

  ColumnSchema col1("key", STRING);
  ColumnSchema col2("uint32val", UINT32, true);
  ColumnSchema col3("int32val", INT32);

  vector<ColumnSchema> cols = { col1, col2, col3 };
  Schema schema(cols, 1);

  ASSERT_EQ(sizeof(Slice) + sizeof(uint32_t) + sizeof(int32_t),
            schema.byte_size());
  ASSERT_EQ(3, schema.num_columns());
  ASSERT_EQ(0, schema.column_offset(0));
  ASSERT_EQ(sizeof(Slice), schema.column_offset(1));
  ASSERT_GT(schema.memory_footprint_excluding_this(),
            empty_schema.memory_footprint_excluding_this());

  EXPECT_EQ("Schema [\n"
            "\tkey[string NOT NULL NOT A PARTITION KEY],\n"
            "\tuint32val[uint32 NULLABLE NOT A PARTITION KEY],\n"
            "\tint32val[int32 NOT NULL NOT A PARTITION KEY]\n"
            "]\nproperties: contain_counters: false is_transactional: false "
            "consistency_level: STRONG "
            "use_mangled_column_name: false "
            "is_ysql_catalog_table: false "
            "retain_delete_markers: false",
            schema.ToString());
  EXPECT_EQ("key[string NOT NULL NOT A PARTITION KEY]", schema.column(0).ToString());
  EXPECT_EQ("uint32 NULLABLE NOT A PARTITION KEY", schema.column(1).TypeToString());
}