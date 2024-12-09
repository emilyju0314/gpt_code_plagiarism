static void AttemptToShrinkBox(const FCOORD &rotation, const FCOORD &rerotation, const TBOX &im_box,
                               Image pix, TBOX *slice) {
  TBOX rotated_box(*slice);
  rotated_box.rotate(rerotation);
  TBOX rotated_im_box(im_box);
  rotated_im_box.rotate(rerotation);
  int left = rotated_box.left() - rotated_im_box.left();
  int right = rotated_box.right() - rotated_im_box.left();
  int top = rotated_im_box.top() - rotated_box.top();
  int bottom = rotated_im_box.top() - rotated_box.bottom();
  ImageFind::BoundsWithinRect(pix, &left, &top, &right, &bottom);
  top = rotated_im_box.top() - top;
  bottom = rotated_im_box.top() - bottom;
  left += rotated_im_box.left();
  right += rotated_im_box.left();
  rotated_box.set_to_given_coords(left, bottom, right, top);
  rotated_box.rotate(rotation);
  slice->set_left(rotated_box.left());
  slice->set_right(rotated_box.right());
}