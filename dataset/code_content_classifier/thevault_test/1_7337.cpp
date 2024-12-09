void Fl_Widget::draw_backdrop() const {
  if (align() & FL_ALIGN_IMAGE_BACKDROP) {
    const Fl_Image *img = image();
    // if there is no image, we will not draw the deimage either
    if (img && deimage() && !active_r())
      img = deimage();
    if (img) 
      ((Fl_Image*)img)->draw(x_+(w_-img->w())/2, y_+(h_-img->h())/2);
  }
}