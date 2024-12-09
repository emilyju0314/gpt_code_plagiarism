TWERD *TWERD::PolygonalCopy(bool allow_detailed_fx, WERD *src) {
  auto *tessword = new TWERD;
  tessword->latin_script = src->flag(W_SCRIPT_IS_LATIN);
  C_BLOB_IT b_it(src->cblob_list());
  for (b_it.mark_cycle_pt(); !b_it.cycled_list(); b_it.forward()) {
    C_BLOB *blob = b_it.data();
    TBLOB *tblob = TBLOB::PolygonalCopy(allow_detailed_fx, blob);
    tessword->blobs.push_back(tblob);
  }
  return tessword;
}