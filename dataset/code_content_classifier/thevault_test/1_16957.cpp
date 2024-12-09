static CordRep* RemoveSuffixFrom(CordRep* node, size_t n) {
  if (n >= node->length) return nullptr;
  if (n == 0) return CordRep::Ref(node);
  absl::InlinedVector<CordRep*, kInlinedVectorSize> lhs_stack;
  bool inplace_ok = node->refcount.IsOne();

  while (node->tag == CONCAT) {
    assert(n <= node->length);
    if (n < node->concat()->right->length) {
      // Push left to stack, descend right.
      lhs_stack.push_back(node->concat()->left);
      node = node->concat()->right;
    } else {
      // Drop right, descend left.
      n -= node->concat()->right->length;
      node = node->concat()->left;
    }
    inplace_ok = inplace_ok && node->refcount.IsOne();
  }
  assert(n <= node->length);

  if (n == 0) {
    CordRep::Ref(node);
  } else if (inplace_ok && node->tag != EXTERNAL) {
    // Consider making a new buffer if the current node capacity is much
    // larger than the new length.
    CordRep::Ref(node);
    node->length -= n;
  } else {
    size_t start = 0;
    size_t len = node->length - n;
    if (node->tag == SUBSTRING) {
      start = node->substring()->start;
      node = node->substring()->child;
    }
    node = NewSubstring(CordRep::Ref(node), start, len);
  }
  while (!lhs_stack.empty()) {
    node = Concat(CordRep::Ref(lhs_stack.back()), node);
    lhs_stack.pop_back();
  }
  return node;
}