static void PrintPath(int length, const BLOB_CHOICE **blob_choices, const UNICHARSET &unicharset,
                      const char *label, FILE *output_file) {
  float rating = 0.0f;
  float certainty = 0.0f;
  for (int i = 0; i < length; ++i) {
    const BLOB_CHOICE *blob_choice = blob_choices[i];
    fprintf(output_file, "%s", unicharset.id_to_unichar(blob_choice->unichar_id()));
    rating += blob_choice->rating();
    if (certainty > blob_choice->certainty()) {
      certainty = blob_choice->certainty();
    }
  }
  fprintf(output_file, "\t%s\t%.4f\t%.4f\n", label, rating, certainty);
}