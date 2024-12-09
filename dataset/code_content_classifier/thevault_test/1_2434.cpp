string String_Token_Stream::location_() const {
  // search backwards four endlines
  unsigned begin;
  unsigned count = 0;
  for (begin = pos_; begin > 0; --begin) {
    if (text_[begin] == '\n') {
      if (++count == 4)
        break;
    }
  }
  Check(text_.size() < UINT_MAX);
  auto const end = static_cast<unsigned>(text_.size());
  unsigned i;
  for (i = begin; i < end; ++i) {
    char const c = text_[i];
    if (i >= pos_ && c == '\n') {
      break;
    }
  }
  // This kruftiness is to create the location string with a single allocation.
  string Result;
  Result.reserve(6 + i - begin);
  Result.insert(0U, "near\n", 5U);
  Result.insert(Result.end(), text_.begin() + begin, text_.begin() + i);
  Result.insert(Result.end(), 1U, '\n');
  return Result;
}