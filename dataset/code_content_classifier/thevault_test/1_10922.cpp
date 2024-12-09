uint64_t RecodeBeamSearch::ComputeCodeHash(int code, bool dup,
                                           const RecodeNode *prev) const {
  uint64_t hash = prev == nullptr ? 0 : prev->code_hash;
  if (!dup && code != null_char_) {
    int num_classes = recoder_.code_range();
    uint64_t carry = (((hash >> 32) * num_classes) >> 32);
    hash *= num_classes;
    hash += carry;
    hash += code;
  }
  return hash;
}