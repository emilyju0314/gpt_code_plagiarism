fuchsia::setui::SettingsObject InitialSettingsObject() {
  auto data = fuchsia::setui::SettingData::New();
  data->set_time_zone_value(fuchsia::setui::TimeZoneInfo{});
  fuchsia::setui::SettingsObject object{
      .setting_type = fuchsia::setui::SettingType::TIME_ZONE,
  };
  FX_CHECK(data->Clone(&object.data) == ZX_OK);
  return object;
}