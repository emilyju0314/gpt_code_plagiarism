void WERD_RES::SetupBlamerBundle() {
  if (blamer_bundle != nullptr) {
    blamer_bundle->SetupNormTruthWord(denorm);
  }
}