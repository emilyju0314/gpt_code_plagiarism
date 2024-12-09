static inline bool PrepareAppendRegion(CordRep* root, char** region,
                                       size_t* size, size_t max_length) {
  if (root->tag == RING && root->refcount.IsOne()) {
    Span<char> span = root->ring()->GetAppendBuffer(max_length);
    if (!span.empty()) {
      *region = span.data();
      *size = span.size();
      return true;
    }
  }

  // Search down the right-hand path for a non-full FLAT node.
  CordRep* dst = root;
  while (dst->tag == CONCAT && dst->refcount.IsOne()) {
    dst = dst->concat()->right;
  }

  if (dst->tag < FLAT || !dst->refcount.IsOne()) {
    *region = nullptr;
    *size = 0;
    return false;
  }

  const size_t in_use = dst->length;
  const size_t capacity = dst->flat()->Capacity();
  if (in_use == capacity) {
    *region = nullptr;
    *size = 0;
    return false;
  }

  size_t size_increase = std::min(capacity - in_use, max_length);

  // We need to update the length fields for all nodes, including the leaf node.
  for (CordRep* rep = root; rep != dst; rep = rep->concat()->right) {
    rep->length += size_increase;
  }
  dst->length += size_increase;

  *region = dst->flat()->Data() + in_use;
  *size = size_increase;
  return true;
}