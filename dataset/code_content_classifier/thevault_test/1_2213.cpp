std::optional<fuchsia::setui::IntlSettings> IntlSettingsFrom(
    const fuchsia::setui::SettingsObject& setting) {
  if (!setting.data.is_intl()) {
    return std::nullopt;
  }
  return setting.data.intl();
}