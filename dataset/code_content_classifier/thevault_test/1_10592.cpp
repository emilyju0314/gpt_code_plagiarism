int ImageFind::CountPixelsInRotatedBox(TBOX box, const TBOX &im_box, const FCOORD &rotation,
                                       Image pix) {
  // Intersect it with the image box.
  box &= im_box; // This is in-place box intersection.
  if (box.null_box()) {
    return 0;
  }
  box.rotate(rotation);
  TBOX rotated_im_box(im_box);
  rotated_im_box.rotate(rotation);
  Image rect_pix = pixCreate(box.width(), box.height(), 1);
  pixRasterop(rect_pix, 0, 0, box.width(), box.height(), PIX_SRC, pix,
              box.left() - rotated_im_box.left(), rotated_im_box.top() - box.top());
  l_int32 result;
  pixCountPixels(rect_pix, &result, nullptr);
  rect_pix.destroy();
  return result;
}