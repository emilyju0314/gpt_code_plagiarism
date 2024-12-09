bool NonOverlappingRectanglesFastPropagator::PropagateTwoBoxes(
    int b1, int b2, SchedulingConstraintHelper* x_dim) {
  // For each direction and each order, we test if the boxes can be disjoint.
  const int state = (x_dim->EndMin(b1) <= x_dim->StartMax(b2)) +
                    2 * (x_dim->EndMin(b2) <= x_dim->StartMax(b1));

  const auto left_box_before_right_box = [](int left, int right,
                                            SchedulingConstraintHelper* x_dim) {
    // left box pushes right box.
    const IntegerValue left_end_min = x_dim->EndMin(left);
    if (left_end_min > x_dim->StartMin(right)) {
      x_dim->ClearReason();
      x_dim->AddReasonForBeingBefore(left, right);
      x_dim->AddEndMinReason(left, left_end_min);
      RETURN_IF_FALSE(x_dim->IncreaseStartMin(right, left_end_min));
    }

    // right box pushes left box.
    const IntegerValue right_start_max = x_dim->StartMax(right);
    if (right_start_max < x_dim->EndMax(left)) {
      x_dim->ClearReason();
      x_dim->AddReasonForBeingBefore(left, right);
      x_dim->AddStartMaxReason(right, right_start_max);
      RETURN_IF_FALSE(x_dim->DecreaseEndMax(left, right_start_max));
    }

    return true;
  };

  switch (state) {
    case 0: {  // Conflict.
      x_dim->ClearReason();
      x_dim->AddReasonForBeingBefore(b1, b2);
      x_dim->AddReasonForBeingBefore(b2, b1);
      return x_dim->ReportConflict();
    }
    case 1: {  // b1 is left of b2.
      return left_box_before_right_box(b1, b2, x_dim);
    }
    case 2: {  // b2 is left of b1.
      return left_box_before_right_box(b2, b1, x_dim);
    }
    default: {  // Nothing to deduce.
      return true;
    }
  }
}