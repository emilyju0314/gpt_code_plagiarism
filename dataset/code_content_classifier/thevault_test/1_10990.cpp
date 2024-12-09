void WERD_RES::ReplaceBestChoice(WERD_CHOICE *choice) {
  best_choice = choice;
  RebuildBestState();
  SetupBoxWord();
  // Make up a fake reject map of the right length to keep the
  // rejection pass happy.
  reject_map.initialise(best_state.size());
  done = tess_accepted = tess_would_adapt = true;
  SetScriptPositions();
}