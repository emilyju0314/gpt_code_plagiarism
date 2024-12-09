static void SegmentBBox(const FCOORD &pt1, const FCOORD &pt2, TBOX *bbox) {
  FCOORD step(pt2);
  step -= pt1;
  int x1 = IntCastRounded(std::min(pt1.x(), pt2.x()));
  int x2 = IntCastRounded(std::max(pt1.x(), pt2.x()));
  if (x2 > x1) {
    int y1 = IntCastRounded(pt1.y() + step.y() * (x1 + 0.5 - pt1.x()) / step.x());
    int y2 = IntCastRounded(pt1.y() + step.y() * (x2 - 0.5 - pt1.x()) / step.x());
    TBOX point(x1, std::min(y1, y2), x2, std::max(y1, y2));
    *bbox += point;
  }
  int y1 = IntCastRounded(std::min(pt1.y(), pt2.y()));
  int y2 = IntCastRounded(std::max(pt1.y(), pt2.y()));
  if (y2 > y1) {
    int x1 = IntCastRounded(pt1.x() + step.x() * (y1 + 0.5 - pt1.y()) / step.y());
    int x2 = IntCastRounded(pt1.x() + step.x() * (y2 - 0.5 - pt1.y()) / step.y());
    TBOX point(std::min(x1, x2), y1, std::max(x1, x2), y2);
    *bbox += point;
  }
}