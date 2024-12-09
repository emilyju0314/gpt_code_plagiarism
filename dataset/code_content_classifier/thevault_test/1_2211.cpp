fit::result<std::map<std::string, std::string>, zx_status_t> GetUnicodeExtensionsForDenormalization(
    const modular::RawProfileData& raw_data) {
  auto primary_calendar_id_result = ExtractBcp47CalendarId(raw_data.calendar_ids[0]);
  if (primary_calendar_id_result.is_error()) {
    FX_LOGS(ERROR) << "Bad calendar ID: " << raw_data.calendar_ids[0];
    return fit::error(primary_calendar_id_result.error());
  }
  const std::string& primary_calendar_id = primary_calendar_id_result.value();

  const std::string& primary_tz_id_iana = raw_data.time_zone_ids[0].id;
  const char* primary_tz_id =
      uloc_toUnicodeLocaleType(LocaleKeys::kTimeZone.c_str(), primary_tz_id_iana.c_str());
  if (primary_tz_id == nullptr) {
    FX_LOGS(ERROR) << "Bad time zone ID: " << primary_tz_id_iana;
    return fit::error(ZX_ERR_INVALID_ARGS);
  }

  std::map<std::string, std::string> extensions{{LocaleKeys::kCalendar, primary_calendar_id},
                                                {LocaleKeys::kTimeZone, primary_tz_id}};
  if (raw_data.hour_cycle != nullptr) {
    switch (raw_data.hour_cycle->setting) {
      case fuchsia::setui::HourCycle::H12:
        extensions[LocaleKeys::kHourCycle] = "h12";
        break;
      case fuchsia::setui::HourCycle::H23:
        extensions[LocaleKeys::kHourCycle] = "h23";
        break;
      default:
        // If we ever add a different hour cycle setting, e.g. "locale default", this will work.
        // So, a bit of future-proofing here.  I wonder if it's going to be such.
        break;
    }
  }
  return fit::ok(extensions);
}