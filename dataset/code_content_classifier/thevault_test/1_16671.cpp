bool is_equal(const MXNode* node, casadi_int depth) const override {
      if (op_==node->op()) {
        if (MX::is_equal(dep(0), node->dep(0), depth-1)
            && MX::is_equal(dep(1), node->dep(1), depth-1)) {
          // If arguments are equal
          return true;
        } else {
          // If arguments are flipped
          return operation_checker<CommChecker>(op_)
            && MX::is_equal(dep(1), node->dep(0), depth-1)
            && MX::is_equal(dep(0), node->dep(1), depth-1);
        }
      } else {
        return false;
      }
    }