void fl_copy_offscreen(int x, int y, int w, int h, Fl_Offscreen pixmap, int srcx, int srcy) {
  if( fl_graphics_driver == fl_display_device->driver()) {
    fl_copy_offscreen_to_display(x, y, w, h, pixmap, srcx, srcy);
  }
  else { // when copy is not to the display
    fl_begin_offscreen(pixmap);
    uchar *img = fl_read_image(NULL, srcx, srcy, w, h, 0);
    fl_end_offscreen();
    fl_draw_image(img, x, y, w, h, 3, 0);
    delete img;
  }
}