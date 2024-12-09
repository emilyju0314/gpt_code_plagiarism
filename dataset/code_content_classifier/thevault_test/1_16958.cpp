inline absl::string_view Cord::InlineRep::FindFlatStartPiece() const {
  if (!is_tree()) {
    return absl::string_view(data_.as_chars(), data_.inline_size());
  }

  CordRep* node = tree();
  if (node->tag >= FLAT) {
    return absl::string_view(node->flat()->Data(), node->length);
  }

  if (node->tag == EXTERNAL) {
    return absl::string_view(node->external()->base, node->length);
  }

  if (node->tag == RING) {
    return node->ring()->entry_data(node->ring()->head());
  }

  // Walk down the left branches until we hit a non-CONCAT node.
  while (node->tag == CONCAT) {
    node = node->concat()->left;
  }

  // Get the child node if we encounter a SUBSTRING.
  size_t offset = 0;
  size_t length = node->length;
  assert(length != 0);

  if (node->tag == SUBSTRING) {
    offset = node->substring()->start;
    node = node->substring()->child;
  }

  if (node->tag >= FLAT) {
    return absl::string_view(node->flat()->Data() + offset, length);
  }

  assert((node->tag == EXTERNAL) && "Expect FLAT or EXTERNAL node here");

  return absl::string_view(node->external()->base + offset, length);
}