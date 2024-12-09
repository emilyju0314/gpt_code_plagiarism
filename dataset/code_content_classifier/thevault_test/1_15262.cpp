void UnitTestImpl::ListTestsMatchingFilter() {
  for (size_t i = 0; i < test_cases_.size(); i++) {
    const TestCase* const test_case = test_cases_[i];
    bool printed_test_case_name = false;

    for (size_t j = 0; j < test_case->test_info_list().size(); j++) {
      const TestInfo* const test_info =
          test_case->test_info_list()[j];
      if (test_info->matches_filter()) {
        if (!printed_test_case_name) {
          printed_test_case_name = true;
          printf("%s.\n", test_case->name());
        }
        printf("  %s\n", test_info->name());
      }
    }
  }
  fflush(stdout);
}