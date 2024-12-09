TEST(CustomOptions, DebugString) {
  DescriptorPool pool;

  FileDescriptorProto file_proto;
  MessageOptions::descriptor()->file()->CopyTo(&file_proto);
  ASSERT_TRUE(pool.BuildFile(file_proto) != nullptr);

  // Add "foo.proto":
  //   import "google/protobuf/descriptor.proto";
  //   package "protobuf_unittest";
  //   option (protobuf_unittest.cc_option1) = 1;
  //   option (protobuf_unittest.cc_option2) = 2;
  //   extend google.protobuf.FieldOptions {
  //     optional int32 cc_option1 = 7736974;
  //     optional int32 cc_option2 = 7736975;
  //   }
  ASSERT_TRUE(TextFormat::ParseFromString(
      "name: \"foo.proto\" "
      "package: \"protobuf_unittest\" "
      "dependency: \"google/protobuf/descriptor.proto\" "
      "options { "
      "  uninterpreted_option { "
      "    name { "
      "      name_part: \"protobuf_unittest.cc_option1\" "
      "      is_extension: true "
      "    } "
      "    positive_int_value: 1 "
      "  } "
      "  uninterpreted_option { "
      "    name { "
      "      name_part: \"protobuf_unittest.cc_option2\" "
      "      is_extension: true "
      "    } "
      "    positive_int_value: 2 "
      "  } "
      "} "
      "extension { "
      "  name: \"cc_option1\" "
      "  extendee: \".google.protobuf.FileOptions\" "
      // This field number is intentionally chosen to be the same as
      // (.fileopt1) defined in unittest_custom_options.proto (linked
      // in this test binary). This is to test whether we are messing
      // generated pool with custom descriptor pools when dealing with
      // custom options.
      "  number: 7736974 "
      "  label: LABEL_OPTIONAL "
      "  type: TYPE_INT32 "
      "}"
      "extension { "
      "  name: \"cc_option2\" "
      "  extendee: \".google.protobuf.FileOptions\" "
      "  number: 7736975 "
      "  label: LABEL_OPTIONAL "
      "  type: TYPE_INT32 "
      "}",
      &file_proto));
  const FileDescriptor* descriptor = pool.BuildFile(file_proto);
  ASSERT_TRUE(descriptor != nullptr);

  EXPECT_EQ(2, descriptor->extension_count());

  ASSERT_EQ(
      "syntax = \"proto2\";\n"
      "\n"
      "import \"google/protobuf/descriptor.proto\";\n"
      "package protobuf_unittest;\n"
      "\n"
      "option (.protobuf_unittest.cc_option1) = 1;\n"
      "option (.protobuf_unittest.cc_option2) = 2;\n"
      "\n"
      "extend .google.protobuf.FileOptions {\n"
      "  optional int32 cc_option1 = 7736974;\n"
      "  optional int32 cc_option2 = 7736975;\n"
      "}\n"
      "\n",
      descriptor->DebugString());
}