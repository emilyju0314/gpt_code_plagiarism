std::vector<int> SymVariables::getStateFrom(const BDD &bdd) const {
  std::vector<int> vals;
  BDD current = bdd;
  for (int var = 0; var < preconditionBDDs.size(); var++) {
    for (int val = 0; val < preconditionBDDs[var].size(); val++) {
      BDD aux = current * preconditionBDDs[var][val];
      if (!aux.IsZero()) {
        current = aux;
        vals.push_back(val);
        break;
      }
    }
  }
  return vals;
}