bool TBOX::DeSerialize(bool swap, FILE *fp) {
  if (!bot_left.DeSerialize(swap, fp)) {
    return false;
  }
  if (!top_right.DeSerialize(swap, fp)) {
    return false;
  }
  return true;
}