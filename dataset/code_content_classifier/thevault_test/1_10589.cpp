bool ImageFind::BoundsWithinRect(Image pix, int *x_start, int *y_start, int *x_end, int *y_end) {
  Box *input_box = boxCreate(*x_start, *y_start, *x_end - *x_start, *y_end - *y_start);
  Box *output_box = nullptr;
  pixClipBoxToForeground(pix, input_box, nullptr, &output_box);
  bool result = output_box != nullptr;
  if (result) {
    l_int32 x, y, width, height;
    boxGetGeometry(output_box, &x, &y, &width, &height);
    *x_start = x;
    *y_start = y;
    *x_end = x + width;
    *y_end = y + height;
    boxDestroy(&output_box);
  }
  boxDestroy(&input_box);
  return result;
}