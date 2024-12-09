TEST_F(SourceLocationTest, GetSourceLocation_BogusSourceCodeInfo) {
  SourceLocation loc;

  const FileDescriptor* file_desc =
      GOOGLE_CHECK_NOTNULL(pool_.FindFileByName("/test/test.proto"));

  FileDescriptorProto proto;
  file_desc->CopyTo(&proto);  // Note, this discards the SourceCodeInfo.
  EXPECT_FALSE(proto.has_source_code_info());
  SourceCodeInfo_Location* loc_msg =
      proto.mutable_source_code_info()->add_location();
  loc_msg->add_path(1);
  loc_msg->add_path(2);
  loc_msg->add_path(3);
  loc_msg->add_span(4);
  loc_msg->add_span(5);
  loc_msg->add_span(6);

  DescriptorPool bad2_pool(&pool_);
  const FileDescriptor* bad2_file_desc =
      GOOGLE_CHECK_NOTNULL(bad2_pool.BuildFile(proto));
  const Descriptor* bad2_a_desc = bad2_file_desc->FindMessageTypeByName("A");
  EXPECT_FALSE(bad2_a_desc->GetSourceLocation(&loc));
}