TEST(CustomOptions, AggregateOptions) {
  const Descriptor* msg = protobuf_unittest::AggregateMessage::descriptor();
  const FileDescriptor* file = msg->file();
  const FieldDescriptor* field = msg->FindFieldByName("fieldname");
  const EnumDescriptor* enumd = file->FindEnumTypeByName("AggregateEnum");
  const EnumValueDescriptor* enumv = enumd->FindValueByName("VALUE");
  const ServiceDescriptor* service =
      file->FindServiceByName("AggregateService");
  const MethodDescriptor* method = service->FindMethodByName("Method");

  // Tests for the different types of data embedded in fileopt
  const protobuf_unittest::Aggregate& file_options =
      file->options().GetExtension(protobuf_unittest::fileopt);
  EXPECT_EQ(100, file_options.i());
  EXPECT_EQ("FileAnnotation", file_options.s());
  EXPECT_EQ("NestedFileAnnotation", file_options.sub().s());
  EXPECT_EQ("FileExtensionAnnotation",
            file_options.file().GetExtension(protobuf_unittest::fileopt).s());
  EXPECT_EQ("EmbeddedMessageSetElement",
            file_options.mset()
                .GetExtension(protobuf_unittest::AggregateMessageSetElement ::
                                  message_set_extension)
                .s());

  // Simple tests for all the other types of annotations
  EXPECT_EQ("MessageAnnotation",
            msg->options().GetExtension(protobuf_unittest::msgopt).s());
  EXPECT_EQ("FieldAnnotation",
            field->options().GetExtension(protobuf_unittest::fieldopt).s());
  EXPECT_EQ("EnumAnnotation",
            enumd->options().GetExtension(protobuf_unittest::enumopt).s());
  EXPECT_EQ("EnumValueAnnotation",
            enumv->options().GetExtension(protobuf_unittest::enumvalopt).s());
  EXPECT_EQ("ServiceAnnotation",
            service->options().GetExtension(protobuf_unittest::serviceopt).s());
  EXPECT_EQ("MethodAnnotation",
            method->options().GetExtension(protobuf_unittest::methodopt).s());
}