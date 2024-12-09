void UNICHARSET::set_ranges_empty() {
  for (auto &uc : unichars) {
    uc.properties.SetRangesEmpty();
  }
}