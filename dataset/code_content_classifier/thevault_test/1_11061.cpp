BoxWord *BoxWord::CopyFromNormalized(TWERD *tessword) {
  auto *boxword = new BoxWord();
  // Count the blobs.
  boxword->length_ = tessword->NumBlobs();
  // Allocate memory.
  boxword->boxes_.reserve(boxword->length_);

  for (unsigned b = 0; b < boxword->length_; ++b) {
    TBLOB *tblob = tessword->blobs[b];
    TBOX blob_box;
    for (TESSLINE *outline = tblob->outlines; outline != nullptr;
         outline = outline->next) {
      EDGEPT *edgept = outline->loop;
      // Iterate over the edges.
      do {
        if (!edgept->IsHidden() || !edgept->prev->IsHidden()) {
          ICOORD pos(edgept->pos.x, edgept->pos.y);
          TPOINT denormed;
          tblob->denorm().DenormTransform(nullptr, edgept->pos, &denormed);
          pos.set_x(denormed.x);
          pos.set_y(denormed.y);
          TBOX pt_box(pos, pos);
          blob_box += pt_box;
        }
        edgept = edgept->next;
      } while (edgept != outline->loop);
    }
    boxword->boxes_.push_back(blob_box);
  }
  boxword->ComputeBoundingBox();
  return boxword;
}