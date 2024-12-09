void OSResults::print_scores(int orientation_id) const {
  for (int j = 0; j < kMaxNumberOfScripts; ++j) {
    if (scripts_na[orientation_id][j]) {
      tprintf("%12s\t: %f\n", unicharset->get_script_from_script_id(j),
              scripts_na[orientation_id][j]);
    }
  }
}