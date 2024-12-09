TEST(KeyboardTest, DoubleCountingKeys) {
  hid::DeviceDescriptor* dev_desc = nullptr;
  auto parse_res =
      hid::ParseReportDescriptor(double_keys_keyboard, sizeof(double_keys_keyboard), &dev_desc);
  ASSERT_EQ(hid::ParseResult::kParseOk, parse_res);

  // Test the descriptor parses correctly.
  hid_input_report::Keyboard keyboard;

  EXPECT_EQ(hid_input_report::ParseResult::kParseOk,
            keyboard.ParseReportDescriptor(dev_desc->report[0]));
  hid_input_report::ReportDescriptor report_descriptor = keyboard.GetDescriptor();

  hid_input_report::KeyboardDescriptor* keyboard_descriptor =
      std::get_if<hid_input_report::KeyboardDescriptor>(&report_descriptor.descriptor);
  ASSERT_NOT_NULL(keyboard_descriptor);

  EXPECT_EQ(keyboard_descriptor->num_keys, 105U);

  // Test that all of the expected keys are here.
  for (size_t i = 0; i < 97; i++) {
    EXPECT_EQ(*key_util::fuchsia_key_to_hid_key(
                  static_cast<fuchsia::ui::input2::Key>(keyboard_descriptor->keys[i])),
              i + 4);
  }

  for (size_t i = 97; i < 105; i++) {
    EXPECT_EQ(*key_util::fuchsia_key_to_hid_key(
                  static_cast<fuchsia::ui::input2::Key>(keyboard_descriptor->keys[i])),
              0xE0 + (i - 97));
  }
}