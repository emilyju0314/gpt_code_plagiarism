static CordRep* RingNewTree(const char* data, size_t length,
                            size_t alloc_hint) {
  if (length <= kMaxFlatLength) {
    return CreateFlat(data, length, alloc_hint);
  }
  CordRepFlat* flat = CreateFlat(data, kMaxFlatLength, 0);
  data += kMaxFlatLength;
  length -= kMaxFlatLength;
  size_t extra = (length - 1) / kMaxFlatLength + 1;
  auto* root = CordRepRing::Create(flat, extra);
  return CordRepRing::Append(root, {data, length}, alloc_hint);
}