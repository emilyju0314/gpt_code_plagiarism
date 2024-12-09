void WERD_RES::merge_tess_fails() {
  using namespace std::placeholders; // for _1, _2
  if (ConditionalBlobMerge(std::bind(&WERD_RES::BothSpaces, this, _1, _2),
                           nullptr)) {
    unsigned len = best_choice->length();
    ASSERT_HOST(reject_map.length() == len);
    ASSERT_HOST(box_word->length() == len);
  }
}