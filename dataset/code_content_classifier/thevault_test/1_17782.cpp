TEST(KeyboardKeyHandlerTest, WithSlowFrameworkResponse) {
  std::list<MockKeyHandlerDelegate::KeyboardHookCall> hook_history;

  // Capture the scancode of the last redispatched event
  int redispatch_scancode = 0;
  bool delegate_handled = false;
  TestKeyboardKeyHandler handler([&redispatch_scancode](UINT cInputs,
                                                        LPINPUT pInputs,
                                                        int cbSize) -> UINT {
    EXPECT_TRUE(cbSize > 0);
    redispatch_scancode = pInputs->ki.wScan;
    return 1;
  });

  auto delegate1 = std::make_unique<MockKeyHandlerDelegate>(1, &hook_history);
  CallbackHandler& delegate1_handler = delegate1->callback_handler;
  handler.AddDelegate(std::move(delegate1));

  // The first native event.
  EXPECT_EQ(
      handler.KeyboardHook(64, kHandledScanCode, WM_KEYDOWN, L'a', false, true),
      true);

  // The second identical native event, received between the first and its
  // framework response.
  EXPECT_EQ(
      handler.KeyboardHook(64, kHandledScanCode, WM_KEYDOWN, L'a', false, true),
      true);
  EXPECT_EQ(redispatch_scancode, 0);
  EXPECT_EQ(hook_history.size(), 2);

  EXPECT_EQ(handler.HasRedispatched(), false);

  // The first response.
  hook_history.front().callback(false);
  EXPECT_EQ(redispatch_scancode, kHandledScanCode);
  EXPECT_EQ(handler.HasRedispatched(), true);

  // Redispatch the first event.
  EXPECT_EQ(handler.KeyboardHook(64, kHandledScanCode, WM_KEYDOWN, L'a', false,
                                 false),
            false);
  EXPECT_EQ(handler.HasRedispatched(), false);
  redispatch_scancode = 0;

  // The second response.
  hook_history.back().callback(false);
  EXPECT_EQ(redispatch_scancode, kHandledScanCode);
  EXPECT_EQ(handler.HasRedispatched(), true);

  // Redispatch the second event.
  EXPECT_EQ(handler.KeyboardHook(64, kHandledScanCode, WM_KEYDOWN, L'a', false,
                                 false),
            false);

  EXPECT_EQ(handler.HasRedispatched(), false);
  redispatch_scancode = 0;
  hook_history.clear();
}