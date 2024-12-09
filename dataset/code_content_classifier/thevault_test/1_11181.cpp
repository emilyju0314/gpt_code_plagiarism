TBOX TBOX::bounding_union( // box enclosing both
    const TBOX &box) const {
  ICOORD bl; // bottom left
  ICOORD tr; // top right

  if (box.bot_left.x() < bot_left.x()) {
    bl.set_x(box.bot_left.x());
  } else {
    bl.set_x(bot_left.x());
  }

  if (box.top_right.x() > top_right.x()) {
    tr.set_x(box.top_right.x());
  } else {
    tr.set_x(top_right.x());
  }

  if (box.bot_left.y() < bot_left.y()) {
    bl.set_y(box.bot_left.y());
  } else {
    bl.set_y(bot_left.y());
  }

  if (box.top_right.y() > top_right.y()) {
    tr.set_y(box.top_right.y());
  } else {
    tr.set_y(top_right.y());
  }
  return TBOX(bl, tr);
}