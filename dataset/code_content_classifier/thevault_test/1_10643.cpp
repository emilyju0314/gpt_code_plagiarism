void BoxChar::RotateBoxes(float rotation, int xcenter, int ycenter, int start_box, int end_box,
                          std::vector<BoxChar *> *boxes) {
  Boxa *orig = boxaCreate(0);
  for (int i = start_box; i < end_box; ++i) {
    BOX *box = (*boxes)[i]->box_;
    if (box) {
      boxaAddBox(orig, box, L_CLONE);
    }
  }
  Boxa *rotated = boxaRotate(orig, xcenter, ycenter, rotation);
  boxaDestroy(&orig);
  for (int i = start_box, box_ind = 0; i < end_box; ++i) {
    if ((*boxes)[i]->box_) {
      boxDestroy(&((*boxes)[i]->box_));
      (*boxes)[i]->box_ = boxaGetBox(rotated, box_ind++, L_CLONE);
    }
  }
  boxaDestroy(&rotated);
}