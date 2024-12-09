void CheckConstraintViolators(const std::vector<int64>& vars,
                              std::vector<int>* const violators) {
  int dim = vars.size();

  // Check that all indices are unique
  for (int i = 0; i < dim; ++i) {
    for (int k = i + 1; k < dim; ++k) {
      if (vars[i] == vars[k]) {
        violators->push_back(i);
        violators->push_back(k);
      }
    }
  }

  // Check that all differences are unique for each level
  for (int level = 1; level < dim; ++level) {
    for (int i = 0; i < dim - level; ++i) {
      const int difference = vars[i + level] - vars[i];

      for (int k = i + 1; k < dim - level; ++k) {
        if (difference == vars[k + level] - vars[k]) {
          violators->push_back(k + level);
          violators->push_back(k);
          violators->push_back(i + level);
          violators->push_back(i);
        }
      }
    }
  }
}