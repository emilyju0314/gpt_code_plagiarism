TEST_F(ColorTransformHandlerTest, VerifyColorTransform) {
  // Change settings.
  fuchsia::accessibility::ColorTransformConfiguration configuration;
  configuration.set_color_correction(
      fuchsia::accessibility::ColorCorrectionMode::CORRECT_DEUTERANOMALY);
  configuration.set_color_inversion_enabled(false);
  configuration.set_color_adjustment_matrix(kCorrectDeuteranomaly);

  ASSERT_TRUE(configuration.has_color_adjustment_matrix());
  color_transform_handler_->SetColorTransformConfiguration(std::move(configuration), [] {});
  RunLoopUntilIdle();

  // Verify that fake scenic received the correct matrix.
  ASSERT_TRUE(fake_session_->PresentWasCalled());
  auto command = fake_session_->GetFirstCommand();
  ASSERT_TRUE(command.has_value());
  ASSERT_EQ(command.value().Which(), fuchsia::ui::gfx::Command::Tag::kSetDisplayColorConversion);
  ASSERT_EQ(kCorrectDeuteranomaly, command.value().set_display_color_conversion().matrix);
}