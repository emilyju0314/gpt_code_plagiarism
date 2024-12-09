void Cord::InlineRep::AppendArray(const char* src_data, size_t src_size) {
  if (src_size == 0) return;  // memcpy(_, nullptr, 0) is undefined.

  size_t appended = 0;
  CordRep* root = nullptr;
  if (is_tree()) {
    root = data_.as_tree();
    char* region;
    if (PrepareAppendRegion(root, &region, &appended, src_size)) {
      memcpy(region, src_data, appended);
    }
  } else {
    // Try to fit in the inline buffer if possible.
    size_t inline_length = inline_size();
    if (src_size <= kMaxInline - inline_length) {
      // Append new data to embedded array
      memcpy(data_.as_chars() + inline_length, src_data, src_size);
      set_inline_size(inline_length + src_size);
      return;
    }

    // It is possible that src_data == data_, but when we transition from an
    // InlineRep to a tree we need to assign data_ = root via set_tree. To
    // avoid corrupting the source data before we copy it, delay calling
    // set_tree until after we've copied data.
    // We are going from an inline size to beyond inline size. Make the new size
    // either double the inlined size, or the added size + 10%.
    const size_t size1 = inline_length * 2 + src_size;
    const size_t size2 = inline_length + src_size / 10;
    root = CordRepFlat::New(std::max<size_t>(size1, size2));
    appended = std::min(
        src_size, root->flat()->Capacity() - inline_length);
    memcpy(root->flat()->Data(), data_.as_chars(), inline_length);
    memcpy(root->flat()->Data() + inline_length, src_data, appended);
    root->length = inline_length + appended;
    set_tree(root);
  }

  src_data += appended;
  src_size -= appended;
  if (src_size == 0) {
    return;
  }

  if (cord_ring_enabled()) {
    absl::string_view data(src_data, src_size);
    root = ForceRing(root, (data.size() - 1) / kMaxFlatLength + 1);
    replace_tree(CordRepRing::Append(root->ring(), data));
    return;
  }

  // Use new block(s) for any remaining bytes that were not handled above.
  // Alloc extra memory only if the right child of the root of the new tree is
  // going to be a FLAT node, which will permit further inplace appends.
  size_t length = src_size;
  if (src_size < kMaxFlatLength) {
    // The new length is either
    // - old size + 10%
    // - old_size + src_size
    // This will cause a reasonable conservative step-up in size that is still
    // large enough to avoid excessive amounts of small fragments being added.
    length = std::max<size_t>(root->length / 10, src_size);
  }
  set_tree(Concat(root, NewTree(src_data, src_size, length - src_size)));
}