std::vector<size_t> FindNaluStartSequences(const uint8_t* buffer,
                                           size_t buffer_size) {
  std::vector<size_t> sequences;
  // This is sorta like Boyer-Moore, but with only the first optimization step:
  // given a 4-byte sequence we're looking at, if the 4th byte isn't 1 or 0,
  // skip ahead to the next 4-byte sequence. 0s and 1s are relatively rare, so
  // this will skip the majority of reads/checks.
  const uint8_t* end = buffer + buffer_size - 4;
  for (const uint8_t* head = buffer; head < end;) {
    if (head[3] > 1) {
      head += 4;
    } else if (head[3] == 1 && head[2] == 0 && head[1] == 0 && head[0] == 0) {
      sequences.push_back(static_cast<size_t>(head - buffer));
      head += 4;
    } else {
      head++;
    }
  }

  return sequences;
}