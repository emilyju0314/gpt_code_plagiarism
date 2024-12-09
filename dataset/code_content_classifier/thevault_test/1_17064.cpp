TEST_F(FileDescriptorTest, DebugStringRoundTrip) {
  std::set<std::string> visited;
  std::vector<std::pair<std::string, std::string>> debug_strings;
  ExtractDebugString(protobuf_unittest::TestAllTypes::descriptor()->file(),
                     &visited, &debug_strings);
  ExtractDebugString(
      protobuf_unittest::TestMessageWithCustomOptions::descriptor()->file(),
      &visited, &debug_strings);
  ExtractDebugString(proto3_arena_unittest::TestAllTypes::descriptor()->file(),
                     &visited, &debug_strings);
  ASSERT_GE(debug_strings.size(), 3);

  DescriptorPool pool;
  for (int i = 0; i < debug_strings.size(); ++i) {
    const std::string& name = debug_strings[i].first;
    const std::string& content = debug_strings[i].second;
    io::ArrayInputStream input_stream(content.data(), content.size());
    SimpleErrorCollector error_collector;
    io::Tokenizer tokenizer(&input_stream, &error_collector);
    compiler::Parser parser;
    parser.RecordErrorsTo(&error_collector);
    FileDescriptorProto proto;
    ASSERT_TRUE(parser.Parse(&tokenizer, &proto))
        << error_collector.last_error() << "\n"
        << content;
    ASSERT_EQ("", error_collector.last_error());
    proto.set_name(name);
    const FileDescriptor* descriptor = pool.BuildFile(proto);
    ASSERT_TRUE(descriptor != nullptr) << proto.DebugString();
    EXPECT_EQ(content, descriptor->DebugString());
  }
}