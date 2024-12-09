void SEAM::PrintSeams(const char *label, const std::vector<SEAM *> &seams) {
  if (!seams.empty()) {
    tprintf("%s\n", label);
    for (unsigned x = 0; x < seams.size(); ++x) {
      tprintf("%2u:   ", x);
      seams[x]->Print("");
    }
    tprintf("\n");
  }
}