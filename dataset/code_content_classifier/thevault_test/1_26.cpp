uint64_t tag_big_endian() {
  static uint64_t tag = (uint64_t)-1;
  if (tag == -1) {
    tag = (uint64_t)leaf_block(getTagForSymbolName("LblbigEndianBytes{}"));
  }
  return tag;
}