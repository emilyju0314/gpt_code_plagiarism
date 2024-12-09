bool IsXImageRGBFormat(XImage* image) {
  return image->bits_per_pixel == 32 &&
      image->red_mask == 0xff0000 &&
      image->green_mask == 0xff00 &&
      image->blue_mask == 0xff;
}