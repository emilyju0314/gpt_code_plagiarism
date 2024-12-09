std::vector<casadi_int> instruction_input(casadi_int k) const override {
    auto e = algorithm_.at(k);
    if (casadi_math<double>::ndeps(e.op)==2 || e.op==OP_INPUT) {
      return {e.i1, e.i2};
    } else if (casadi_math<double>::ndeps(e.op)==1) {
      return {e.i1};
    } else {
      return {};
    }
  }