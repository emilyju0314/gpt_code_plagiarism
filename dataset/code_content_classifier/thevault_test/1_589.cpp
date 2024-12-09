static void encodeBinding(const OutputSection *osec, uint64_t outSecOff,
                          int64_t addend, Binding &lastBinding,
                          std::vector<BindIR> &opcodes) {
  OutputSegment *seg = osec->parent;
  uint64_t offset = osec->getSegmentOffset() + outSecOff;
  if (lastBinding.segment != seg) {
    opcodes.push_back(
        {static_cast<uint8_t>(BIND_OPCODE_SET_SEGMENT_AND_OFFSET_ULEB |
                              seg->index),
         offset});
    lastBinding.segment = seg;
    lastBinding.offset = offset;
  } else if (lastBinding.offset != offset) {
    opcodes.push_back({BIND_OPCODE_ADD_ADDR_ULEB, offset - lastBinding.offset});
    lastBinding.offset = offset;
  }

  if (lastBinding.addend != addend) {
    opcodes.push_back(
        {BIND_OPCODE_SET_ADDEND_SLEB, static_cast<uint64_t>(addend)});
    lastBinding.addend = addend;
  }

  opcodes.push_back({BIND_OPCODE_DO_BIND, 0});
  // DO_BIND causes dyld to both perform the binding and increment the offset
  lastBinding.offset += target->wordSize;
}