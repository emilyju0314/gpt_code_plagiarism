void
EditView::BoundingBox(BBox &bb) {
  double temp;
  
  // Calculate the world coordinates for the view's canvas
  matrix_.imap(0.0, 0.0, bb.xmin, bb.ymin);
  matrix_.imap(width_, height_, bb.xmax, bb.ymax);

  // Check to make sure xmin, ymin is the lower left corner
  // and xmax, ymax is the upper right
  if (bb.xmin > bb.xmax) {
    temp = bb.xmax;
    bb.xmax = bb.xmin;
    bb.xmin = temp;
  }
  if (bb.ymin > bb.ymax) {
    temp = bb.ymax;
    bb.ymax = bb.ymin;
    bb.ymin = temp;
  }
}