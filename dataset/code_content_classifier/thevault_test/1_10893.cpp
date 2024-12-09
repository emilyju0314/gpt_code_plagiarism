void TBLOB::GetPreciseBoundingBox(TBOX *precise_box) const {
  TBOX box = bounding_box();
  *precise_box = TBOX();
  CollectEdges(box, precise_box, nullptr, nullptr, nullptr);
  precise_box->move(box.botleft());
}