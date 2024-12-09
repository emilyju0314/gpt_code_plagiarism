void SEAM::BreakPieces(const std::vector<SEAM *> &seams, const std::vector<TBLOB *> &blobs,
                       int first, int last) {
  for (int x = first; x < last; ++x) {
    seams[x]->Reveal();
  }

  TESSLINE *outline = blobs[first]->outlines;
  int next_blob = first + 1;

  while (outline != nullptr && next_blob <= last) {
    if (outline->next == blobs[next_blob]->outlines) {
      outline->next = nullptr;
      outline = blobs[next_blob]->outlines;
      ++next_blob;
    } else {
      outline = outline->next;
    }
  }
}