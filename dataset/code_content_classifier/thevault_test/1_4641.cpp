void validateUniversalType(std::string_view uri) {
  // We require a minimum 1 domain and 2 path segements, though up to 4 path
  // segements is likely to be common.
  folly::small_vector<folly::StringPiece, 5> segs;
  folly::splitTo<folly::StringPiece>('/', uri, std::back_inserter(segs));
  check(segs.size() >= 3, "not enough path segments");
  checkDomain(segs[0]);
  size_t i = 1;
  for (; i < segs.size() - 1; ++i) {
    checkPathSegment(segs[i]);
  }
  checkTypeSegment(segs[i]);
}