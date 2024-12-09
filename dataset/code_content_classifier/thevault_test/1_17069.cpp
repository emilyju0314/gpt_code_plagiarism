TEST_F(ValidationErrorTest, ValidateProto3JsonName) {
  // The comparison is case-insensitive.
  BuildFileWithErrors(
      "name: 'foo.proto' "
      "syntax: 'proto3' "
      "message_type {"
      "  name: 'Foo'"
      "  field { name:'name' number:1 label:LABEL_OPTIONAL type:TYPE_INT32 }"
      "  field { name:'Name' number:2 label:LABEL_OPTIONAL type:TYPE_INT32 }"
      "}",
      "foo.proto: Foo: NAME: The JSON camel-case name of field \"Name\" "
      "conflicts with field \"name\". This is not allowed in proto3.\n");
  // Underscores are ignored.
  BuildFileWithErrors(
      "name: 'foo.proto' "
      "syntax: 'proto3' "
      "message_type {"
      "  name: 'Foo'"
      "  field { name:'ab' number:1 label:LABEL_OPTIONAL type:TYPE_INT32 }"
      "  field { name:'_a__b_' number:2 label:LABEL_OPTIONAL type:TYPE_INT32 }"
      "}",
      "foo.proto: Foo: NAME: The JSON camel-case name of field \"_a__b_\" "
      "conflicts with field \"ab\". This is not allowed in proto3.\n");
}