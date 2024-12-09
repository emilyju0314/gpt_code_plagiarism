void MergeIntl(const std::optional<fuchsia::setui::IntlSettings>& intl_settings,
               RawProfileData* new_profile_data) {
  if (!intl_settings.has_value()) {
    return;
  }
  // Replace the old settings with the new.
  switch (intl_settings->temperature_unit) {
    case fuchsia::setui::TemperatureUnit::CELSIUS:
      new_profile_data->temperature_unit = fuchsia::intl::TemperatureUnit::CELSIUS;
      break;
    case fuchsia::setui::TemperatureUnit::FAHRENHEIT:
      new_profile_data->temperature_unit = fuchsia::intl::TemperatureUnit::FAHRENHEIT;
      break;
    default:
      FX_LOGS(WARNING) << "fuchsia.setui gave us an unknown temperature unit enum value: "
                       << static_cast<uint32_t>(intl_settings->temperature_unit);
  }
  if (!intl_settings->locales.empty()) {
    // Do not touch the current locale settings if setui tells us there are no languages
    // set.
    new_profile_data->language_tags.clear();
    for (const auto& locale : intl_settings->locales) {
      new_profile_data->language_tags.emplace_back(fuchsia::intl::LocaleId{.id = locale});
    }
  } else {
    FX_LOGS(WARNING)
        << "fuchsia.setui returned locale settings with no locales; this is not a valid "
           "fuchsia.intl.Profile; not touching the current language settings and proceeding.";
  }
  // Setui does not have a way to leave hour cycle setting to the locale, so we always set it
  // here.  However, if an option comes in to set it, we can do that too.
  new_profile_data->hour_cycle = std::make_unique<HourCycle>(HourCycle{
      .setting = intl_settings->hour_cycle,
  });
}