void TextlineProjection::MoveNonTextlineBlobs(BLOBNBOX_LIST *blobs,
                                              BLOBNBOX_LIST *small_blobs) const {
  BLOBNBOX_IT it(blobs);
  BLOBNBOX_IT small_it(small_blobs);
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    BLOBNBOX *blob = it.data();
    const TBOX &box = blob->bounding_box();
    bool debug = AlignedBlob::WithinTestRegion(2, box.left(), box.bottom());
    if (BoxOutOfHTextline(box, nullptr, debug) && !blob->UniquelyVertical()) {
      blob->ClearNeighbours();
      small_it.add_to_end(it.extract());
    }
  }
}