bool TBOX::Serialize(FILE *fp) const {
  if (!bot_left.Serialize(fp)) {
    return false;
  }
  if (!top_right.Serialize(fp)) {
    return false;
  }
  return true;
}