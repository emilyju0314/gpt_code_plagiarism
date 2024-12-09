TEST_F(SourceLocationTest, GetSourceLocation_MissingSourceCodeInfo) {
  SourceLocation loc;

  const FileDescriptor* file_desc =
      GOOGLE_CHECK_NOTNULL(pool_.FindFileByName("/test/test.proto"));

  FileDescriptorProto proto;
  file_desc->CopyTo(&proto);  // Note, this discards the SourceCodeInfo.
  EXPECT_FALSE(proto.has_source_code_info());

  DescriptorPool bad1_pool(&pool_);
  const FileDescriptor* bad1_file_desc =
      GOOGLE_CHECK_NOTNULL(bad1_pool.BuildFile(proto));
  const Descriptor* bad1_a_desc = bad1_file_desc->FindMessageTypeByName("A");
  EXPECT_FALSE(bad1_a_desc->GetSourceLocation(&loc));
}