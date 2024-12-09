static APInt adjustToPointerSize(const APInt &Offset, unsigned PointerSize) {
  assert(PointerSize <= Offset.getBitWidth() && "Invalid PointerSize!");
  unsigned ShiftBits = Offset.getBitWidth() - PointerSize;
  return (Offset << ShiftBits).ashr(ShiftBits);
}