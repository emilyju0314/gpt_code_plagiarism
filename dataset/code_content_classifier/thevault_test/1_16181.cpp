static Expr allEqualTo(const vector<Iterator>& iterators, Expr idx) {
  if (iterators.size() == 0) {
    return Literal::make(true);
  }

  vector<Expr> iterIdxEqualToIdx;
  for (auto& iter : iterators) {
    iterIdxEqualToIdx.push_back(Eq::make(iter.getIdxVar(), idx));
  }
  return conjunction(iterIdxEqualToIdx);
}