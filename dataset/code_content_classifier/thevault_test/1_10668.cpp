static int direction(const EDGEPT *point) {
  //* direction to return
  int dir = 0;
  //* prev point
  const EDGEPT *prev = point->prev;
  //* next point
  const EDGEPT *next = point->next;

  if (((prev->pos.x <= point->pos.x) && (point->pos.x < next->pos.x)) ||
      ((prev->pos.x < point->pos.x) && (point->pos.x <= next->pos.x))) {
    dir = 1;
  }
  if (((prev->pos.x >= point->pos.x) && (point->pos.x > next->pos.x)) ||
      ((prev->pos.x > point->pos.x) && (point->pos.x >= next->pos.x))) {
    dir = -1;
  }

  return dir;
}