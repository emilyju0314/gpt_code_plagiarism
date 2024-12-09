bool UNICHARSET::GetStrProperties(const char *utf8_str,
                                  UNICHAR_PROPERTIES *props) const {
  props->Init();
  props->SetRangesEmpty();
  int total_unicodes = 0;
  std::vector<UNICHAR_ID> encoding;
  if (!encode_string(utf8_str, true, &encoding, nullptr, nullptr)) {
    return false; // Some part was invalid.
  }
  for (auto it : encoding) {
    int id = it;
    const UNICHAR_PROPERTIES &src_props = unichars[id].properties;
    // Logical OR all the bools.
    if (src_props.isalpha) {
      props->isalpha = true;
    }
    if (src_props.islower) {
      props->islower = true;
    }
    if (src_props.isupper) {
      props->isupper = true;
    }
    if (src_props.isdigit) {
      props->isdigit = true;
    }
    if (src_props.ispunctuation) {
      props->ispunctuation = true;
    }
    if (src_props.isngram) {
      props->isngram = true;
    }
    if (src_props.enabled) {
      props->enabled = true;
    }
    // Min/max the tops/bottoms.
    UpdateRange(src_props.min_bottom, &props->min_bottom, &props->max_bottom);
    UpdateRange(src_props.max_bottom, &props->min_bottom, &props->max_bottom);
    UpdateRange(src_props.min_top, &props->min_top, &props->max_top);
    UpdateRange(src_props.max_top, &props->min_top, &props->max_top);
    float bearing = props->advance + src_props.bearing;
    if (total_unicodes == 0 || bearing < props->bearing) {
      props->bearing = bearing;
      props->bearing_sd = props->advance_sd + src_props.bearing_sd;
    }
    props->advance += src_props.advance;
    props->advance_sd += src_props.advance_sd;
    // With a single width, just use the widths stored in the unicharset.
    props->width = src_props.width;
    props->width_sd = src_props.width_sd;
    // Use the first script id, other_case, mirror, direction.
    // Note that these will need translation, except direction.
    if (total_unicodes == 0) {
      props->script_id = src_props.script_id;
      props->other_case = src_props.other_case;
      props->mirror = src_props.mirror;
      props->direction = src_props.direction;
    }
    // The normed string for the compound character is the concatenation of
    // the normed versions of the individual characters.
    props->normed += src_props.normed;
    ++total_unicodes;
  }
  if (total_unicodes > 1) {
    // Estimate the total widths from the advance - bearing.
    props->width = props->advance - props->bearing;
    props->width_sd = props->advance_sd + props->bearing_sd;
  }
  return total_unicodes > 0;
}