void
QueueItem::locate(float x, float y, float dx, float dy) {
  // Bottom Left Corner
  px_[0] = x;
  py_[0] = y;

  // Bottom Right Corner 
  x += dy;
  y -= dx;
  px_[1] = x;
  py_[1] = y;

  // Top Right Corner
  x += dx;
  y += dy;
  px_[2] = x;
  py_[2] = y;

  // Top  Left Corner
  x -= dy;
  y += dx;
  px_[3] = x;
  py_[3] = y;

  update_bb();
}