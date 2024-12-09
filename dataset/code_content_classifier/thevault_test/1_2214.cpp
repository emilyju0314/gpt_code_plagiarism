void MergeTimeZone(const std::optional<std::string>& timezone_id,
                   RawProfileData* new_profile_data) {
  if (!timezone_id.has_value()) {
    return;
  }
  // Merge the new value with the old.
  new_profile_data->time_zone_ids = {TimeZoneId{.id = *timezone_id}};
}