ColumnSpanningType ColPartitionSet::SpanningType(
    int resolution, int left, int right, int height, int y, int left_margin,
    int right_margin, int *first_col, int *last_col, int *first_spanned_col) {
  *first_col = -1;
  *last_col = -1;
  *first_spanned_col = -1;
  int margin_columns = 0;
  ColPartition_IT it(&parts_);
  int col_index = 1;
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward(), col_index += 2) {
    ColPartition *part = it.data();
    if (part->ColumnContains(left, y) ||
        (it.at_first() && part->ColumnContains(left + height, y))) {
      // In the default case, first_col is set, but columns_spanned remains
      // zero, so first_col will get reset in the first column genuinely
      // spanned, but we can tell the difference from a noise partition
      // that touches no column.
      *first_col = col_index;
      if (part->ColumnContains(right, y) ||
          (it.at_last() && part->ColumnContains(right - height, y))) {
        // Both within a single column.
        *last_col = col_index;
        return CST_FLOWING;
      }
      if (left_margin <= part->LeftAtY(y)) {
        // It completely spans this column.
        *first_spanned_col = col_index;
        margin_columns = 1;
      }
    } else if (part->ColumnContains(right, y) ||
               (it.at_last() && part->ColumnContains(right - height, y))) {
      if (*first_col < 0) {
        // It started in-between.
        *first_col = col_index - 1;
      }
      if (right_margin >= part->RightAtY(y)) {
        // It completely spans this column.
        if (margin_columns == 0) {
          *first_spanned_col = col_index;
        }
        ++margin_columns;
      }
      *last_col = col_index;
      break;
    } else if (left < part->LeftAtY(y) && right > part->RightAtY(y)) {
      // Neither left nor right are contained within, so it spans this
      // column.
      if (*first_col < 0) {
        // It started in between the previous column and the current column.
        *first_col = col_index - 1;
      }
      if (margin_columns == 0) {
        *first_spanned_col = col_index;
      }
      *last_col = col_index;
    } else if (right < part->LeftAtY(y)) {
      // We have gone past the end.
      *last_col = col_index - 1;
      if (*first_col < 0) {
        // It must lie completely between columns =>noise.
        *first_col = col_index - 1;
      }
      break;
    }
  }
  if (*first_col < 0) {
    *first_col = col_index - 1; // The last in-between.
  }
  if (*last_col < 0) {
    *last_col = col_index - 1; // The last in-between.
  }
  ASSERT_HOST(*first_col >= 0 && *last_col >= 0);
  ASSERT_HOST(*first_col <= *last_col);
  if (*first_col == *last_col && right - left < kMinColumnWidth * resolution) {
    // Neither end was in a column, and it didn't span any, so it lies
    // entirely between columns, therefore noise.
    return CST_NOISE;
  } else if (margin_columns <= 1) {
    // An exception for headings that stick outside of single-column text.
    if (margin_columns == 1 && parts_.singleton()) {
      return CST_HEADING;
    }
    // It is a pullout, as left and right were not in the same column, but
    // it doesn't go to the edge of its start and end.
    return CST_PULLOUT;
  }
  // Its margins went to the edges of first and last columns => heading.
  return CST_HEADING;
}