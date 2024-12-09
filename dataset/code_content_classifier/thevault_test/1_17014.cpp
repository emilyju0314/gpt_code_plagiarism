const FieldDescriptor* F(const std::string& name) {
  const FieldDescriptor* result =
      unittest::TestAllTypes::descriptor()->FindFieldByName(name);
  GOOGLE_CHECK(result != NULL);
  return result;
}