void UNICHARSET::UNICHAR_PROPERTIES::ExpandRangesFrom(
    const UNICHAR_PROPERTIES &src) {
  UpdateRange(src.min_bottom, &min_bottom, &max_bottom);
  UpdateRange(src.max_bottom, &min_bottom, &max_bottom);
  UpdateRange(src.min_top, &min_top, &max_top);
  UpdateRange(src.max_top, &min_top, &max_top);
  if (src.width_sd > width_sd) {
    width = src.width;
    width_sd = src.width_sd;
  }
  if (src.bearing_sd > bearing_sd) {
    bearing = src.bearing;
    bearing_sd = src.bearing_sd;
  }
  if (src.advance_sd > advance_sd) {
    advance = src.advance;
    advance_sd = src.advance_sd;
  }
}