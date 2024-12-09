void Merge(const fuchsia::setui::SettingsObject& setting, RawProfileData* new_profile_data) {
  FX_CHECK(new_profile_data != nullptr);
  // Using the same Notify function for all settings type, here we process on
  // a case by case basis.
  const auto setting_type = setting.setting_type;
  switch (setting_type) {
    case fuchsia::setui::SettingType::TIME_ZONE: {
      const auto timezone_id = TimeZoneIdFrom(setting);
      MergeTimeZone(timezone_id, new_profile_data);
    } break;
    case fuchsia::setui::SettingType::INTL: {
      const auto intl = IntlSettingsFrom(setting);
      MergeIntl(intl, new_profile_data);
    } break;
    default:
      // The default branch should, in theory, not trigger since in the setup code we subscribe
      // only to specific SettingsType values.   If it does, it could be a bug on the server side,
      // or could be that we have a new setting interest but have not registered to process it.

      // operator<< is not implemented for SettingType, so we just print the corresponding
      // unsigned value.  See FIDL definition of the enum for the value mapping.
      FX_LOGS(WARNING) << "Got unexpected setting type: " << static_cast<uint32_t>(setting_type);
      break;
  }
}