static void PrintMatrixPaths(int col, int dim, const MATRIX &ratings, int length,
                             const BLOB_CHOICE **blob_choices, const UNICHARSET &unicharset,
                             const char *label, FILE *output_file) {
  for (int row = col; row < dim && row - col < ratings.bandwidth(); ++row) {
    if (ratings.get(col, row) != NOT_CLASSIFIED) {
      BLOB_CHOICE_IT bc_it(ratings.get(col, row));
      for (bc_it.mark_cycle_pt(); !bc_it.cycled_list(); bc_it.forward()) {
        blob_choices[length] = bc_it.data();
        if (row + 1 < dim) {
          PrintMatrixPaths(row + 1, dim, ratings, length + 1, blob_choices, unicharset, label,
                           output_file);
        } else {
          PrintPath(length + 1, blob_choices, unicharset, label, output_file);
        }
      }
    }
  }
}