static std::string EmbedAggregateValue(const char* value) {
  return strings::Substitute(
      "name: \"foo.proto\" "
      "dependency: \"google/protobuf/descriptor.proto\" "
      "message_type { name: \"Foo\" } "
      "extension { name: \"foo\" number: 7672757 label: LABEL_OPTIONAL "
      "            type: TYPE_MESSAGE type_name: \"Foo\" "
      "            extendee: \"google.protobuf.FileOptions\" }"
      "options { uninterpreted_option { name { name_part: \"foo\" "
      "                                        is_extension: true } "
      "                                 $0 } }",
      value);
}