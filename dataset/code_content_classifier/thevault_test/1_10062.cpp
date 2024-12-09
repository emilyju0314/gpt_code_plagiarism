TEST(TestDataLogDisabled, VerifyLoggingWorks) {
  ASSERT_EQ(0, DataLog::CreateLog());
  // Generate a table_name name and assure it's an empty string
  // (dummy behavior).
  std::string table_name = DataLog::Combine("table", 1);
  ASSERT_EQ("", table_name);
  PerformLogging(table_name);
  DataLog::ReturnLog();
}