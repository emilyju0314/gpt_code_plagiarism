TEST(KeyboardKeyHandlerTest, NeverRedispatchShiftRightKeyDown) {
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

  auto delegate = std::make_unique<MockKeyHandlerDelegate>(1, &hook_history);
  delegate->callback_handler = respond_false;
  handler.AddDelegate(std::move(delegate));

  // Press ShiftRight and the delegate responds false.

  delegate_handled = handler.KeyboardHook(VK_RSHIFT, kScanCodeShiftRight,
                                          WM_KEYDOWN, 0, false, false);
  EXPECT_EQ(delegate_handled, true);
  EXPECT_EQ(redispatch_scancode, 0);
  EXPECT_EQ(hook_history.size(), 1);

  EXPECT_EQ(handler.HasRedispatched(), false);
  redispatch_scancode = 0;
  hook_history.clear();
}