int TextlineProjection::DistanceOfBoxFromBox(const TBOX &from_box, const TBOX &to_box,
                                             bool horizontal_textline, const DENORM *denorm,
                                             bool debug) const {
  // The parallel_gap is the horizontal gap between a horizontal textline and
  // the box. Analogous for vertical.
  int parallel_gap = 0;
  // start_pt is the box end of the line to be modified for curved space.
  TPOINT start_pt;
  // end_pt is the partition end of the line to be modified for curved space.
  TPOINT end_pt;
  if (horizontal_textline) {
    parallel_gap = from_box.x_gap(to_box) + from_box.width();
    start_pt.x = (from_box.left() + from_box.right()) / 2;
    end_pt.x = start_pt.x;
    if (from_box.top() - to_box.top() >= to_box.bottom() - from_box.bottom()) {
      start_pt.y = from_box.top();
      end_pt.y = std::min(to_box.top(), start_pt.y);
    } else {
      start_pt.y = from_box.bottom();
      end_pt.y = std::max(to_box.bottom(), start_pt.y);
    }
  } else {
    parallel_gap = from_box.y_gap(to_box) + from_box.height();
    if (from_box.right() - to_box.right() >= to_box.left() - from_box.left()) {
      start_pt.x = from_box.right();
      end_pt.x = std::min(to_box.right(), start_pt.x);
    } else {
      start_pt.x = from_box.left();
      end_pt.x = std::max(to_box.left(), start_pt.x);
    }
    start_pt.y = (from_box.bottom() + from_box.top()) / 2;
    end_pt.y = start_pt.y;
  }
  // The perpendicular gap is the max vertical distance gap out of:
  // top of from_box to to_box top and bottom of from_box to to_box bottom.
  // This value is then modified for curved projection space.
  // Analogous for vertical.
  int perpendicular_gap = 0;
  // If start_pt == end_pt, then the from_box lies entirely within the to_box
  // (in the perpendicular direction), so we don't need to calculate the
  // perpendicular_gap.
  if (start_pt.x != end_pt.x || start_pt.y != end_pt.y) {
    if (denorm != nullptr) {
      // Denormalize the start and end.
      denorm->DenormTransform(nullptr, start_pt, &start_pt);
      denorm->DenormTransform(nullptr, end_pt, &end_pt);
    }
    if (abs(start_pt.y - end_pt.y) >= abs(start_pt.x - end_pt.x)) {
      perpendicular_gap = VerticalDistance(debug, start_pt.x, start_pt.y, end_pt.y);
    } else {
      perpendicular_gap = HorizontalDistance(debug, start_pt.x, end_pt.x, start_pt.y);
    }
  }
  // The parallel_gap weighs less than the perpendicular_gap.
  return perpendicular_gap + parallel_gap / kParaPerpDistRatio;
}