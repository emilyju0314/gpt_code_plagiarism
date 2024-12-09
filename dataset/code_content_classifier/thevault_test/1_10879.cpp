TBLOB *TBLOB::PolygonalCopy(bool allow_detailed_fx, C_BLOB *src) {
  auto *tblob = new TBLOB;
  ApproximateOutlineList(allow_detailed_fx, src->out_list(), false, &tblob->outlines);
  return tblob;
}