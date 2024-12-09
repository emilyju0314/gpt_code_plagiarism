static void TruncateBoxToMissNonText(int x_middle, int y_middle, bool split_on_x, Image nontext_map,
                                     TBOX *bbox) {
  TBOX box1(*bbox);
  TBOX box2(*bbox);
  TBOX im_box;
  if (split_on_x) {
    box1.set_right(x_middle);
    im_box = BoundsWithinBox(nontext_map, box1);
    if (!im_box.null_box()) {
      box1.set_left(im_box.right());
    }
    box2.set_left(x_middle);
    im_box = BoundsWithinBox(nontext_map, box2);
    if (!im_box.null_box()) {
      box2.set_right(im_box.left());
    }
  } else {
    box1.set_bottom(y_middle);
    im_box = BoundsWithinBox(nontext_map, box1);
    if (!im_box.null_box()) {
      box1.set_top(im_box.bottom());
    }
    box2.set_top(y_middle);
    im_box = BoundsWithinBox(nontext_map, box2);
    if (!im_box.null_box()) {
      box2.set_bottom(im_box.top());
    }
  }
  box1 += box2;
  *bbox = box1;
}