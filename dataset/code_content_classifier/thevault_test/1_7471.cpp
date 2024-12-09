ScaleMove(FK *knot, float step_size = 1e-6, float STEP_CHANGE = 0.01) :
    BasicMove(step_size, STEP_CHANGE) {
    this->knot = knot; 
    this->old_value = 1.0;
  }