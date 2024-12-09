RawProfileData GetDefaultRawData(const std::optional<RawProfileData>& prototype) {
  return prototype.has_value() ? CloneStruct(*prototype)
                               : RawProfileData{
                                     .language_tags = {LocaleId{.id = "en-US"}},
                                     .time_zone_ids = {TimeZoneId{.id = kDefaultTimeZoneId}},
                                     .calendar_ids = {CalendarId{.id = "und-u-ca-gregory"}},
                                     .temperature_unit = TemperatureUnit::FAHRENHEIT,
                                 };
}