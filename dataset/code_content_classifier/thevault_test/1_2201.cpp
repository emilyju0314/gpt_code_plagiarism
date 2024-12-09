TEST_F(CrashpadAgentIntegrationTest, CrashReporter_SmokeTest) {
  FileCrashReport();
  EXPECT_THAT(GetCobaltCrashStates(), UnorderedElementsAreArray({
                                          CrashState::Filed,
                                          CrashState::Archived,
                                      }));
}