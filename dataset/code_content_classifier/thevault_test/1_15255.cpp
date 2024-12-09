TestInfo::TestInfo(const char* a_test_case_name,
                   const char* a_name,
                   const char* a_test_case_comment,
                   const char* a_comment,
                   internal::TypeId fixture_class_id,
                   internal::TestFactoryBase* factory) {
  impl_ = new internal::TestInfoImpl(this, a_test_case_name, a_name,
                                     a_test_case_comment, a_comment,
                                     fixture_class_id, factory);
}