void UnicharCompress::DefragmentCodeValues(int encoded_null) {
  // There may not be any Hangul, but even if there is, it is possible that not
  // all codes are used. Likewise with the Han encoding, it is possible that not
  // all numbers of strokes are used.
  ComputeCodeRange();
  std::vector<int> offsets(code_range_);
  // Find which codes are used
  for (auto &code : encoder_) {
    for (int i = 0; i < code.length(); ++i) {
      offsets[code(i)] = 1;
    }
  }
  // Compute offsets based on code use.
  int offset = 0;
  for (unsigned i = 0; i < offsets.size(); ++i) {
    // If not used, decrement everything above here.
    // We are moving encoded_null to the end, so it is not "used".
    if (offsets[i] == 0 || i == static_cast<unsigned>(encoded_null)) {
      --offset;
    } else {
      offsets[i] = offset;
    }
  }
  if (encoded_null >= 0) {
    // The encoded_null is moving to the end, for the benefit of TensorFlow,
    // which is offsets.size() + offsets.back().
    offsets[encoded_null] = offsets.size() + offsets.back() - encoded_null;
  }
  // Now apply the offsets.
  for (auto &c : encoder_) {
    RecodedCharID *code = &c;
    for (int i = 0; i < code->length(); ++i) {
      int value = (*code)(i);
      code->Set(i, value + offsets[value]);
    }
  }
  ComputeCodeRange();
}