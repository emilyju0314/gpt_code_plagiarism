TEST_F(AppUnitTest, MagnifierGestureWithScreenReader) {
  MockPointerEventRegistry registry(&context_provider_);
  MockSetUIAccessibility setui(&context_provider_);
  a11y_manager::App app(context_provider_.TakeContext());

  MockMagnificationHandler mag_handler;
  fidl::Binding<fuchsia::accessibility::MagnificationHandler> mag_handler_binding(&mag_handler);
  {
    fuchsia::accessibility::MagnifierPtr magnifier;
    context_provider_.ConnectToPublicService(magnifier.NewRequest());
    magnifier->RegisterHandler(mag_handler_binding.NewBinding());
  }

  fuchsia::settings::AccessibilitySettings settings;
  settings.set_screen_reader(true);
  settings.set_enable_magnification(true);
  setui.Set(std::move(settings), [](auto) {});

  SendPointerEvents(&registry.listener(), 3 * TapEvents(1, {}));
  RunLoopFor(a11y::Magnifier::kTransitionPeriod);

  EXPECT_GT(mag_handler.transform().scale, 1);
}