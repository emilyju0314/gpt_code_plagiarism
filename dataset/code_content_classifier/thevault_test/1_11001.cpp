void WERD_RES::fix_quotes() {
  if (!uch_set->contains_unichar("\"") ||
      !uch_set->get_enabled(uch_set->unichar_to_id("\""))) {
    return; // Don't create it if it is disallowed.
  }

  using namespace std::placeholders; // for _1, _2
  ConditionalBlobMerge(std::bind(&WERD_RES::BothQuotes, this, _1, _2), nullptr);
}