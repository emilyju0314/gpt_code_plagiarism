void WERD_RES::CopySimpleFields(const WERD_RES &source) {
  tess_failed = source.tess_failed;
  tess_accepted = source.tess_accepted;
  tess_would_adapt = source.tess_would_adapt;
  done = source.done;
  unlv_crunch_mode = source.unlv_crunch_mode;
  small_caps = source.small_caps;
  odd_size = source.odd_size;
  fontinfo = source.fontinfo;
  fontinfo2 = source.fontinfo2;
  fontinfo_id_count = source.fontinfo_id_count;
  fontinfo_id2_count = source.fontinfo_id2_count;
  x_height = source.x_height;
  caps_height = source.caps_height;
  baseline_shift = source.baseline_shift;
  guessed_x_ht = source.guessed_x_ht;
  guessed_caps_ht = source.guessed_caps_ht;
  reject_spaces = source.reject_spaces;
  uch_set = source.uch_set;
  tesseract = source.tesseract;
}