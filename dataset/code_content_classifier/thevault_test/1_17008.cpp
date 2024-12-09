std::vector<uint8_t> BuildRfc1034Name(const size_t name_len,
                                      std::string* dotted_str) {
  CHECK(dotted_str != nullptr);
  auto ChoosePrintableCharLambda = [](uint8_t n) { return n % 26 + 'A'; };
  const size_t max_label_len = 63;
  std::vector<uint8_t> data;

  dotted_str->clear();
  while (data.size() < name_len) {
    // Write the null label representing the root node.
    if (data.size() == name_len - 1) {
      data.push_back(0);
      break;
    }

    // Compute the size of the next label.
    //
    // Suppose |name_len| is 8 and |data.size()| is 4. We want |label_len| to be
    // 2 so that we are correctly aligned to put 0 in the final position.
    //
    //    3  'A' 'B' 'C'  _   _   _   _
    //    0   1   2   3   4   5   6   7
    const size_t label_len =
        std::min(name_len - data.size() - 2, max_label_len);
    // Write the length octet
    data.push_back(label_len);

    // Write |label_len| bytes of label data
    const size_t size_with_label = data.size() + label_len;
    while (data.size() < size_with_label) {
      const uint8_t chr = ChoosePrintableCharLambda(data.size());
      data.push_back(chr);
      dotted_str->push_back(chr);

      CHECK(data.size() <= name_len);
    }

    // Write a trailing dot after every label
    dotted_str->push_back('.');
  }

  // Omit the final dot
  if (!dotted_str->empty())
    dotted_str->pop_back();

  CHECK(data.size() == name_len);
  return data;
}