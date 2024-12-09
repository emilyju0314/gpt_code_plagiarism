void start_seam_list(TWERD *word, std::vector<SEAM *> *seam_array) {
  seam_array->clear();
  TPOINT location;

  for (unsigned b = 1; b < word->NumBlobs(); ++b) {
    TBOX bbox = word->blobs[b - 1]->bounding_box();
    TBOX nbox = word->blobs[b]->bounding_box();
    location.x = (bbox.right() + nbox.left()) / 2;
    location.y = (bbox.bottom() + bbox.top() + nbox.bottom() + nbox.top()) / 4;
    seam_array->push_back(new SEAM(0.0f, location));
  }
}