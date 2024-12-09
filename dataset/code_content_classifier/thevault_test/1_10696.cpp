static void YOutlierPieces(WERD_RES *word, int rebuilt_blob_index, int super_y_bottom,
                           int sub_y_top, ScriptPos *leading_pos, int *num_leading_outliers,
                           ScriptPos *trailing_pos, int *num_trailing_outliers) {
  ScriptPos sp_unused1, sp_unused2;
  int unused1, unused2;
  if (!leading_pos) {
    leading_pos = &sp_unused1;
  }
  if (!num_leading_outliers) {
    num_leading_outliers = &unused1;
  }
  if (!trailing_pos) {
    trailing_pos = &sp_unused2;
  }
  if (!num_trailing_outliers) {
    num_trailing_outliers = &unused2;
  }

  *num_leading_outliers = *num_trailing_outliers = 0;
  *leading_pos = *trailing_pos = SP_NORMAL;

  int chopped_start = LeadingUnicharsToChopped(word, rebuilt_blob_index);
  int num_chopped_pieces = word->best_state[rebuilt_blob_index];
  ScriptPos last_pos = SP_NORMAL;
  int trailing_outliers = 0;
  for (int i = 0; i < num_chopped_pieces; i++) {
    TBOX box = word->chopped_word->blobs[chopped_start + i]->bounding_box();
    ScriptPos pos = SP_NORMAL;
    if (box.bottom() >= super_y_bottom) {
      pos = SP_SUPERSCRIPT;
    } else if (box.top() <= sub_y_top) {
      pos = SP_SUBSCRIPT;
    }
    if (pos == SP_NORMAL) {
      if (trailing_outliers == i) {
        *num_leading_outliers = trailing_outliers;
        *leading_pos = last_pos;
      }
      trailing_outliers = 0;
    } else {
      if (pos == last_pos) {
        trailing_outliers++;
      } else {
        trailing_outliers = 1;
      }
    }
    last_pos = pos;
  }
  *num_trailing_outliers = trailing_outliers;
  *trailing_pos = last_pos;
}