void WERD_RES::SetAllScriptPositions(tesseract::ScriptPos position) {
  raw_choice->SetAllScriptPositions(position);
  WERD_CHOICE_IT wc_it(&best_choices);
  for (wc_it.mark_cycle_pt(); !wc_it.cycled_list(); wc_it.forward()) {
    wc_it.data()->SetAllScriptPositions(position);
  }
}