void UnicharCompress::SetupDecoder() {
  Cleanup();
  is_valid_start_.clear();
  is_valid_start_.resize(code_range_);
  for (unsigned c = 0; c < encoder_.size(); ++c) {
    const RecodedCharID &code = encoder_[c];
    decoder_[code] = c;
    is_valid_start_[code(0)] = true;
    RecodedCharID prefix = code;
    int len = code.length() - 1;
    prefix.Truncate(len);
    auto final_it = final_codes_.find(prefix);
    if (final_it == final_codes_.end()) {
      auto *code_list = new std::vector<int>;
      code_list->push_back(code(len));
      final_codes_[prefix] = code_list;
      while (--len >= 0) {
        prefix.Truncate(len);
        auto next_it = next_codes_.find(prefix);
        if (next_it == next_codes_.end()) {
          auto *code_list = new std::vector<int>;
          code_list->push_back(code(len));
          next_codes_[prefix] = code_list;
        } else {
          // We still have to search the list as we may get here via multiple
          // lengths of code.
          if (!contains(*next_it->second, code(len))) {
            next_it->second->push_back(code(len));
          }
          break; // This prefix has been processed.
        }
      }
    } else {
      if (!contains(*final_it->second, code(len))) {
        final_it->second->push_back(code(len));
      }
    }
  }
}