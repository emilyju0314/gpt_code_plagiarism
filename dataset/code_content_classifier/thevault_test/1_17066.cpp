TEST(CustomOptions, OptionsWithIncompatibleDescriptors) {
  DescriptorPool pool;

  FileDescriptorProto file_proto;
  MessageOptions::descriptor()->file()->CopyTo(&file_proto);
  ASSERT_TRUE(pool.BuildFile(file_proto) != nullptr);

  // Create a new file descriptor proto containing a subset of the
  // messages defined in google/protobuf/unittest_custom_options.proto.
  file_proto.Clear();
  file_proto.set_name("unittest_custom_options.proto");
  file_proto.set_package("protobuf_unittest");
  file_proto.add_dependency("google/protobuf/descriptor.proto");

  // Add the "required_enum_opt" extension.
  FieldDescriptorProto* extension = file_proto.add_extension();
  protobuf_unittest::OldOptionType::descriptor()
      ->file()
      ->FindExtensionByName("required_enum_opt")
      ->CopyTo(extension);

  // Add a test message that uses the "required_enum_opt" option.
  DescriptorProto* test_message_type = file_proto.add_message_type();
  protobuf_unittest::TestMessageWithRequiredEnumOption::descriptor()->CopyTo(
      test_message_type);

  // Instruct the extension to use NewOptionType instead of
  // OldOptionType, and add the descriptor of NewOptionType.
  extension->set_type_name(".protobuf_unittest.NewOptionType");
  DescriptorProto* new_option_type = file_proto.add_message_type();
  protobuf_unittest::NewOptionType::descriptor()->CopyTo(new_option_type);

  // Replace the value of the "required_enum_opt" option used in the
  // test message with an enum value that only exists in NewOptionType.
  ASSERT_TRUE(
      TextFormat::ParseFromString("uninterpreted_option { "
                                  "  name { "
                                  "    name_part: 'required_enum_opt' "
                                  "    is_extension: true "
                                  "  } "
                                  "  aggregate_value: 'value: NEW_VALUE'"
                                  "}",
                                  test_message_type->mutable_options()));

  // Adding the file descriptor to the pool should fail.
  EXPECT_TRUE(pool.BuildFile(file_proto) == nullptr);
}