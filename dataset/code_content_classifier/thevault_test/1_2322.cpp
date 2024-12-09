TEST(KeyboardTest, BootKeyboard) {
  size_t descriptor_size;
  const uint8_t* boot_keyboard_descriptor = get_boot_kbd_report_desc(&descriptor_size);

  hid::DeviceDescriptor* dev_desc = nullptr;
  auto parse_res = hid::ParseReportDescriptor(boot_keyboard_descriptor, descriptor_size, &dev_desc);
  ASSERT_EQ(hid::ParseResult::kParseOk, parse_res);

  hid_input_report::Keyboard keyboard;

  EXPECT_EQ(hid_input_report::ParseResult::kParseOk,
            keyboard.ParseReportDescriptor(dev_desc->report[0]));
  hid_input_report::ReportDescriptor report_descriptor = keyboard.GetDescriptor();

  hid_input_report::KeyboardDescriptor* keyboard_descriptor =
      std::get_if<hid_input_report::KeyboardDescriptor>(&report_descriptor.descriptor);
  ASSERT_NOT_NULL(keyboard_descriptor);

  EXPECT_EQ(keyboard_descriptor->num_keys, 105U);

  // Test a report parses correctly.
  hid_boot_kbd_report kbd_report = {};
  kbd_report.modifier = HID_KBD_MODIFIER_LEFT_SHIFT | HID_KBD_MODIFIER_RIGHT_GUI;
  kbd_report.usage[0] = HID_USAGE_KEY_A;
  kbd_report.usage[1] = HID_USAGE_KEY_NON_US_BACKSLASH;
  kbd_report.usage[2] = HID_USAGE_KEY_UP;

  hid_input_report::Report report = {};
  EXPECT_EQ(
      hid_input_report::ParseResult::kParseOk,
      keyboard.ParseReport(reinterpret_cast<uint8_t*>(&kbd_report), sizeof(kbd_report), &report));

  hid_input_report::KeyboardReport* keyboard_report =
      std::get_if<hid_input_report::KeyboardReport>(&report.report);
  ASSERT_NOT_NULL(keyboard_report);
  ASSERT_EQ(keyboard_report->num_pressed_keys, 5U);
  EXPECT_EQ(keyboard_report->pressed_keys[0], llcpp::fuchsia::ui::input2::Key::LEFT_SHIFT);
  EXPECT_EQ(keyboard_report->pressed_keys[1], llcpp::fuchsia::ui::input2::Key::RIGHT_META);
  EXPECT_EQ(keyboard_report->pressed_keys[2], llcpp::fuchsia::ui::input2::Key::A);
  EXPECT_EQ(keyboard_report->pressed_keys[3], llcpp::fuchsia::ui::input2::Key::NON_US_BACKSLASH);
  EXPECT_EQ(keyboard_report->pressed_keys[4], llcpp::fuchsia::ui::input2::Key::UP);
}