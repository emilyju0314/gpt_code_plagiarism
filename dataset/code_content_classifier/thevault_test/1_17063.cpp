DescriptorProto* AddMessage(FileDescriptorProto* file,
                            const std::string& name) {
  DescriptorProto* result = file->add_message_type();
  result->set_name(name);
  return result;
}