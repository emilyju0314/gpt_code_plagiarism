TEST_F(AppUnitTest, OffersTtsManagerServices) {
  a11y_manager::App app = a11y_manager::App(context_provider_.TakeContext());
  RunLoopUntilIdle();
  fuchsia::accessibility::tts::TtsManagerPtr tts_manager;
  context_provider_.ConnectToPublicService(tts_manager.NewRequest());
  RunLoopUntilIdle();
  ASSERT_TRUE(tts_manager.is_bound());
}