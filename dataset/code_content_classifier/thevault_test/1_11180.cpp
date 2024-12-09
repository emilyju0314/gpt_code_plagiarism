TBOX TBOX::intersection( // shared area box
    const TBOX &box) const {
  TDimension left;
  TDimension bottom;
  TDimension right;
  TDimension top;
  if (overlap(box)) {
    if (box.bot_left.x() > bot_left.x()) {
      left = box.bot_left.x();
    } else {
      left = bot_left.x();
    }

    if (box.top_right.x() < top_right.x()) {
      right = box.top_right.x();
    } else {
      right = top_right.x();
    }

    if (box.bot_left.y() > bot_left.y()) {
      bottom = box.bot_left.y();
    } else {
      bottom = bot_left.y();
    }

    if (box.top_right.y() < top_right.y()) {
      top = box.top_right.y();
    } else {
      top = top_right.y();
    }
  } else {
    left = INT16_MAX;
    bottom = INT16_MAX;
    top = -INT16_MAX;
    right = -INT16_MAX;
  }
  return TBOX(left, bottom, right, top);
}