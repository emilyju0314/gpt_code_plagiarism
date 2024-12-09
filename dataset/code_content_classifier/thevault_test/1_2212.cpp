std::optional<std::string> TimeZoneIdFrom(const fuchsia::setui::SettingsObject& setting) {
  if (setting.setting_type != fuchsia::setui::SettingType::TIME_ZONE) {
    // Should never happen since the Watch/Listen protocol ensures the setting matches.
    return std::nullopt;
  }
  const fuchsia::setui::TimeZoneInfo& timezone_info = setting.data.time_zone_value();
  if (timezone_info.current == nullptr) {
    return std::nullopt;
  }
  const auto* timezone = setting.data.time_zone_value().current.get();
  if (timezone_info.current->id.empty()) {
    // Weird data in the timezone field causes us to not update anything.
    return std::nullopt;
  }
  return std::string(timezone->id);
}