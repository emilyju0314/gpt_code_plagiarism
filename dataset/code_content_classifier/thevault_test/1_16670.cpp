std::vector<casadi_int> instruction_output(casadi_int k) const override {
    auto e = algorithm_.at(k);
    if (e.op==OP_OUTPUT) {
      return {e.i0, e.i2};
    } else {
      return {e.i0};
    }
  }