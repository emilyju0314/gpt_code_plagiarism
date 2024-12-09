static Expr noneExhausted(const vector<Iterator>& iterators) {
  vector<Expr> stepIterLqEnd;
  for (auto& iter : iterators) {
    stepIterLqEnd.push_back(Lt::make(iter.getIteratorVar(), iter.end()));
  }
  return conjunction(stepIterLqEnd);
}