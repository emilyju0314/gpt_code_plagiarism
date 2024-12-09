void TBOX::rotate_large(const FCOORD &vec) {
  ICOORD top_left(bot_left.x(), top_right.y());
  ICOORD bottom_right(top_right.x(), bot_left.y());
  top_left.rotate(vec);
  bottom_right.rotate(vec);
  rotate(vec);
  TBOX box2(top_left, bottom_right);
  *this += box2;
}