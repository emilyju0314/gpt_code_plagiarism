TEST(ResultErrorTest, ReportErrorUnknownType) {
  // Check that `reportError` handled `Error`s different than `ResultError`.
  Error err = createStringError(std::make_error_code(std::errc::state_not_recoverable), "ReportErrorUnknownType");
  EXPECT_EQ(reportError(std::move(err)), Result::ErrorUnknown);
}