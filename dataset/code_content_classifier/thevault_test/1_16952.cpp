static CordRep* NewTree(const char* data,
                        size_t length,
                        size_t alloc_hint) {
  if (length == 0) return nullptr;
  if (cord_ring_enabled()) {
    return RingNewTree(data, length, alloc_hint);
  }
  absl::FixedArray<CordRep*> reps((length - 1) / kMaxFlatLength + 1);
  size_t n = 0;
  do {
    const size_t len = std::min(length, kMaxFlatLength);
    CordRepFlat* rep = CordRepFlat::New(len + alloc_hint);
    rep->length = len;
    memcpy(rep->Data(), data, len);
    reps[n++] = VerifyTree(rep);
    data += len;
    length -= len;
  } while (length != 0);
  return MakeBalancedTree(reps.data(), n);
}