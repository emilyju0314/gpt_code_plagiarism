TEST_F(AppUnitTest, ListenerRemoveOneByOne) {
  MockPointerEventRegistry registry(&context_provider_);
  MockSetUIAccessibility setui(&context_provider_);
  a11y_manager::App app(context_provider_.TakeContext());

  fuchsia::settings::AccessibilitySettings settings;
  settings.set_screen_reader(true);
  settings.set_enable_magnification(true);
  setui.Set(std::move(settings), [](auto) {});

  settings.set_screen_reader(false);
  settings.set_enable_magnification(true);
  setui.Set(std::move(settings), [](auto) {});

  RunLoopUntilIdle();

  EXPECT_EQ(app.state().screen_reader_enabled(), false);
  EXPECT_EQ(app.state().magnifier_enabled(), true);

  ASSERT_TRUE(registry.listener());
  EXPECT_EQ(SendUnrecognizedGesture(&registry.listener()), EventHandling::REJECTED);

  settings.set_enable_magnification(false);
  setui.Set(std::move(settings), [](auto) {});

  RunLoopUntilIdle();
  EXPECT_FALSE(registry.listener());
}