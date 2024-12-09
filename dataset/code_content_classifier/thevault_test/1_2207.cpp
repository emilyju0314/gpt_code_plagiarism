TEST_F(ColorTransformHandlerTest, TransformMissingMatrix) {
  // Change settings.
  fuchsia::accessibility::ColorTransformConfiguration configuration;
  configuration.set_color_correction(
      fuchsia::accessibility::ColorCorrectionMode::CORRECT_DEUTERANOMALY);
  configuration.set_color_inversion_enabled(false);
  EXPECT_FALSE(configuration.has_color_adjustment_matrix());

  color_transform_handler_->SetColorTransformConfiguration(std::move(configuration), [] {});
  RunLoopUntilIdle();

  // Verify that fake scenic was not called.
  ASSERT_FALSE(fake_session_->PresentWasCalled());
}