bool ImageFind::BlankImageInBetween(const TBOX &box1, const TBOX &box2, const TBOX &im_box,
                                    const FCOORD &rotation, Image pix) {
  TBOX search_box(box1);
  search_box += box2;
  if (box1.x_gap(box2) >= box1.y_gap(box2)) {
    if (box1.x_gap(box2) <= 0) {
      return true;
    }
    search_box.set_left(std::min(box1.right(), box2.right()));
    search_box.set_right(std::max(box1.left(), box2.left()));
  } else {
    if (box1.y_gap(box2) <= 0) {
      return true;
    }
    search_box.set_top(std::max(box1.bottom(), box2.bottom()));
    search_box.set_bottom(std::min(box1.top(), box2.top()));
  }
  return CountPixelsInRotatedBox(search_box, im_box, rotation, pix) == 0;
}