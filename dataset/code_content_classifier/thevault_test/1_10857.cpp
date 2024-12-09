void SEAM::JoinPieces(const std::vector<SEAM *> &seams, const std::vector<TBLOB *> &blobs,
                      int first, int last) {
  TESSLINE *outline = blobs[first]->outlines;
  if (!outline) {
    return;
  }

  for (int x = first; x < last; ++x) {
    SEAM *seam = seams[x];
    if (x - seam->widthn_ >= first && x + seam->widthp_ < last) {
      seam->Hide();
    }
    while (outline->next) {
      outline = outline->next;
    }
    outline->next = blobs[x + 1]->outlines;
  }
}