static CordRep* RawConcat(CordRep* left, CordRep* right) {
  // Avoid making degenerate concat nodes (one child is empty)
  if (left == nullptr) return right;
  if (right == nullptr) return left;
  if (left->length == 0) {
    CordRep::Unref(left);
    return right;
  }
  if (right->length == 0) {
    CordRep::Unref(right);
    return left;
  }

  CordRepConcat* rep = new CordRepConcat();
  rep->tag = CONCAT;
  SetConcatChildren(rep, left, right);

  return rep;
}