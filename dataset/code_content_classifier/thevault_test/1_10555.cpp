void OSResults::accumulate(const OSResults &osr) {
  for (int i = 0; i < 4; ++i) {
    orientations[i] += osr.orientations[i];
    for (int j = 0; j < kMaxNumberOfScripts; ++j) {
      scripts_na[i][j] += osr.scripts_na[i][j];
    }
  }
  unicharset = osr.unicharset;
  update_best_orientation();
  update_best_script(best_result.orientation_id);
}