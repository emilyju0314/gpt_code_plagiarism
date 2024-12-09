static TBOX BoundsWithinBox(Image pix, const TBOX &box) {
  int im_height = pixGetHeight(pix);
  Box *input_box = boxCreate(box.left(), im_height - box.top(), box.width(), box.height());
  Box *output_box = nullptr;
  pixClipBoxToForeground(pix, input_box, nullptr, &output_box);
  TBOX result_box;
  if (output_box != nullptr) {
    l_int32 x, y, width, height;
    boxGetGeometry(output_box, &x, &y, &width, &height);
    result_box.set_left(x);
    result_box.set_right(x + width);
    result_box.set_top(im_height - y);
    result_box.set_bottom(result_box.top() - height);
    boxDestroy(&output_box);
  }
  boxDestroy(&input_box);
  return result_box;
}