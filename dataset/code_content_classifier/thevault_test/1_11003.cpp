void WERD_RES::fix_hyphens() {
  if (!uch_set->contains_unichar("-") ||
      !uch_set->get_enabled(uch_set->unichar_to_id("-"))) {
    return; // Don't create it if it is disallowed.
  }

  using namespace std::placeholders; // for _1, _2
  ConditionalBlobMerge(std::bind(&WERD_RES::BothHyphens, this, _1, _2),
                       std::bind(&WERD_RES::HyphenBoxesOverlap, this, _1, _2));
}