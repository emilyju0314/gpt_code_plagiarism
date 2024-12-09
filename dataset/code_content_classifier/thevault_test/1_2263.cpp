uint64_t JoinDR7HWBreakpointMask(uint64_t val, std::initializer_list<size_t> indices = {}) {
  for (size_t index : indices) {
    FXL_DCHECK(index < 4);
    val |= GetHWBreakpointDR7Mask(index);
  }

  return val;
}