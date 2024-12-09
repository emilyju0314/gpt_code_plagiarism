void UNICHARSET::post_load_setup() {
  // Number of alpha chars with the case property minus those without,
  // in order to determine that half the alpha chars have case.
  int net_case_alphas = 0;
  int x_height_alphas = 0;
  int cap_height_alphas = 0;
  top_bottom_set_ = false;
  for (unsigned id = 0; id < unichars.size(); ++id) {
    int min_bottom = 0;
    int max_bottom = UINT8_MAX;
    int min_top = 0;
    int max_top = UINT8_MAX;
    get_top_bottom(id, &min_bottom, &max_bottom, &min_top, &max_top);
    if (min_top > 0) {
      top_bottom_set_ = true;
    }
    if (get_isalpha(id)) {
      if (get_islower(id) || get_isupper(id)) {
        ++net_case_alphas;
      } else {
        --net_case_alphas;
      }
      if (min_top < kMeanlineThreshold && max_top < kMeanlineThreshold) {
        ++x_height_alphas;
      } else if (min_top > kMeanlineThreshold && max_top > kMeanlineThreshold) {
        ++cap_height_alphas;
      }
    }
    set_normed_ids(id);
  }

  script_has_upper_lower_ = net_case_alphas > 0;
  script_has_xheight_ =
      script_has_upper_lower_ ||
      (x_height_alphas > cap_height_alphas * kMinXHeightFraction &&
       cap_height_alphas > x_height_alphas * kMinCapHeightFraction);

  null_sid_ = get_script_id_from_name(null_script);
  ASSERT_HOST(null_sid_ == 0);
  common_sid_ = get_script_id_from_name("Common");
  latin_sid_ = get_script_id_from_name("Latin");
  cyrillic_sid_ = get_script_id_from_name("Cyrillic");
  greek_sid_ = get_script_id_from_name("Greek");
  han_sid_ = get_script_id_from_name("Han");
  hiragana_sid_ = get_script_id_from_name("Hiragana");
  katakana_sid_ = get_script_id_from_name("Katakana");
  thai_sid_ = get_script_id_from_name("Thai");
  hangul_sid_ = get_script_id_from_name("Hangul");

  // Compute default script. Use the highest-counting alpha script, that is
  // not the common script, as that still contains some "alphas".
  int *script_counts = new int[script_table_size_used];
  memset(script_counts, 0, sizeof(*script_counts) * script_table_size_used);
  for (unsigned id = 0; id < unichars.size(); ++id) {
    if (get_isalpha(id)) {
      ++script_counts[get_script(id)];
    }
  }
  default_sid_ = 0;
  for (int s = 1; s < script_table_size_used; ++s) {
    if (script_counts[s] > script_counts[default_sid_] && s != common_sid_) {
      default_sid_ = s;
    }
  }
  delete[] script_counts;
}