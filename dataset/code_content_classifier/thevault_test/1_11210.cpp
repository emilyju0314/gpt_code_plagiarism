void UNICHARSET::UNICHAR_PROPERTIES::SetRangesEmpty() {
  min_bottom = UINT8_MAX;
  max_bottom = 0;
  min_top = UINT8_MAX;
  max_top = 0;
  width = 0.0f;
  width_sd = 0.0f;
  bearing = 0.0f;
  bearing_sd = 0.0f;
  advance = 0.0f;
  advance_sd = 0.0f;
}