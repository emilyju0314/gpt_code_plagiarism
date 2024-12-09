bool AddLinearExpressionMultiple(
    IntegerValue multiplier,
    const std::vector<std::pair<ColIndex, IntegerValue>>& terms,
    gtl::ITIVector<ColIndex, IntegerValue>* dense_vector) {
  for (const std::pair<ColIndex, IntegerValue> term : terms) {
    if (!AddProductTo(multiplier, term.second, &(*dense_vector)[term.first])) {
      return false;
    }
  }
  return true;
}