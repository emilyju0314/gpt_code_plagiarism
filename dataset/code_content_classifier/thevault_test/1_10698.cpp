void Tesseract::GetSubAndSuperscriptCandidates(const WERD_RES *word, int *num_rebuilt_leading,
                                               ScriptPos *leading_pos, float *leading_certainty,
                                               int *num_rebuilt_trailing, ScriptPos *trailing_pos,
                                               float *trailing_certainty, float *avg_certainty,
                                               float *unlikely_threshold) {
  *avg_certainty = *unlikely_threshold = 0.0f;
  *num_rebuilt_leading = *num_rebuilt_trailing = 0;
  *leading_certainty = *trailing_certainty = 0.0f;

  int super_y_bottom = kBlnBaselineOffset + kBlnXHeight * superscript_min_y_bottom;
  int sub_y_top = kBlnBaselineOffset + kBlnXHeight * subscript_max_y_top;

  // Step one: Get an average certainty for "normally placed" characters.

  // Counts here are of blobs in the rebuild_word / unichars in best_choice.
  *leading_pos = *trailing_pos = SP_NORMAL;
  int leading_outliers = 0;
  int trailing_outliers = 0;
  int num_normal = 0;
  float normal_certainty_total = 0.0f;
  float worst_normal_certainty = 0.0f;
  ScriptPos last_pos = SP_NORMAL;
  int num_blobs = word->rebuild_word->NumBlobs();
  for (int b = 0; b < num_blobs; ++b) {
    TBOX box = word->rebuild_word->blobs[b]->bounding_box();
    ScriptPos pos = SP_NORMAL;
    if (box.bottom() >= super_y_bottom) {
      pos = SP_SUPERSCRIPT;
    } else if (box.top() <= sub_y_top) {
      pos = SP_SUBSCRIPT;
    }
    if (pos == SP_NORMAL) {
      if (word->best_choice->unichar_id(b) != 0) {
        float char_certainty = word->best_choice->certainty(b);
        if (char_certainty < worst_normal_certainty) {
          worst_normal_certainty = char_certainty;
        }
        num_normal++;
        normal_certainty_total += char_certainty;
      }
      if (trailing_outliers == b) {
        leading_outliers = trailing_outliers;
        *leading_pos = last_pos;
      }
      trailing_outliers = 0;
    } else {
      if (last_pos == pos) {
        trailing_outliers++;
      } else {
        trailing_outliers = 1;
      }
    }
    last_pos = pos;
  }
  *trailing_pos = last_pos;
  if (num_normal >= 3) { // throw out the worst as an outlier.
    num_normal--;
    normal_certainty_total -= worst_normal_certainty;
  }
  if (num_normal > 0) {
    *avg_certainty = normal_certainty_total / num_normal;
    *unlikely_threshold = superscript_worse_certainty * (*avg_certainty);
  }
  if (num_normal == 0 || (leading_outliers == 0 && trailing_outliers == 0)) {
    return;
  }

  // Step two: Try to split off bits of the word that are both outliers
  //           and have much lower certainty than average
  // Calculate num_leading and leading_certainty.
  for (*leading_certainty = 0.0f, *num_rebuilt_leading = 0; *num_rebuilt_leading < leading_outliers;
       (*num_rebuilt_leading)++) {
    float char_certainty = word->best_choice->certainty(*num_rebuilt_leading);
    if (char_certainty > *unlikely_threshold) {
      break;
    }
    if (char_certainty < *leading_certainty) {
      *leading_certainty = char_certainty;
    }
  }

  // Calculate num_trailing and trailing_certainty.
  for (*trailing_certainty = 0.0f, *num_rebuilt_trailing = 0;
       *num_rebuilt_trailing < trailing_outliers; (*num_rebuilt_trailing)++) {
    int blob_idx = num_blobs - 1 - *num_rebuilt_trailing;
    float char_certainty = word->best_choice->certainty(blob_idx);
    if (char_certainty > *unlikely_threshold) {
      break;
    }
    if (char_certainty < *trailing_certainty) {
      *trailing_certainty = char_certainty;
    }
  }
}