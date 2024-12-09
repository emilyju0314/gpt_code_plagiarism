std::vector<vector<int>> SymVariables::getStatesFrom(const BDD &bdd) const {
  std::vector<vector<int>> res;
  BDD cur = bdd;
  for (size_t i=0; i < numStates(bdd); i++) {
    vector<int> state = getStateFrom(cur);
        cur *= !getStateBDD(state);

        vector<int> retState;
        for (int var = 0; var < preconditionBDDs.size(); var++){
                if (state[var] > model->lastIndex[var] - model->firstIndex[var]) continue;
                retState.push_back(state[var] + model->firstIndex[var]);
        }

        res.push_back(retState);

    if (cur.IsZero())
      return res;
  }
  return res;
}