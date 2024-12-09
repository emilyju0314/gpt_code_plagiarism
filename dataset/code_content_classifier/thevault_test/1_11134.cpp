int32_t C_OUTLINE::count_transitions(int32_t threshold) {
  bool first_was_max_x; // what was first
  bool first_was_max_y;
  bool looking_for_max_x; // what is next
  bool looking_for_min_x;
  bool looking_for_max_y; // what is next
  bool looking_for_min_y;
  int stepindex;       // current step
  int32_t total_steps; // steps to do
                       // current limits
  int32_t max_x, min_x, max_y, min_y;
  int32_t initial_x, initial_y; // initial limits
  int32_t total;                // total changes
  ICOORD pos;                   // position of point
  ICOORD next_step;             // step to next pix

  pos = start_pos();
  total_steps = pathlength();
  total = 0;
  max_x = min_x = pos.x();
  max_y = min_y = pos.y();
  looking_for_max_x = true;
  looking_for_min_x = true;
  looking_for_max_y = true;
  looking_for_min_y = true;
  first_was_max_x = false;
  first_was_max_y = false;
  initial_x = pos.x();
  initial_y = pos.y(); // stop uninit warning
  for (stepindex = 0; stepindex < total_steps; stepindex++) {
    // all intersected
    next_step = step(stepindex);
    pos += next_step;
    if (next_step.x() < 0) {
      if (looking_for_max_x && pos.x() < min_x) {
        min_x = pos.x();
      }
      if (looking_for_min_x && max_x - pos.x() > threshold) {
        if (looking_for_max_x) {
          initial_x = max_x;
          first_was_max_x = false;
        }
        total++;
        looking_for_max_x = true;
        looking_for_min_x = false;
        min_x = pos.x(); // reset min
      }
    } else if (next_step.x() > 0) {
      if (looking_for_min_x && pos.x() > max_x) {
        max_x = pos.x();
      }
      if (looking_for_max_x && pos.x() - min_x > threshold) {
        if (looking_for_min_x) {
          initial_x = min_x; // remember first min
          first_was_max_x = true;
        }
        total++;
        looking_for_max_x = false;
        looking_for_min_x = true;
        max_x = pos.x();
      }
    } else if (next_step.y() < 0) {
      if (looking_for_max_y && pos.y() < min_y) {
        min_y = pos.y();
      }
      if (looking_for_min_y && max_y - pos.y() > threshold) {
        if (looking_for_max_y) {
          initial_y = max_y; // remember first max
          first_was_max_y = false;
        }
        total++;
        looking_for_max_y = true;
        looking_for_min_y = false;
        min_y = pos.y(); // reset min
      }
    } else {
      if (looking_for_min_y && pos.y() > max_y) {
        max_y = pos.y();
      }
      if (looking_for_max_y && pos.y() - min_y > threshold) {
        if (looking_for_min_y) {
          initial_y = min_y; // remember first min
          first_was_max_y = true;
        }
        total++;
        looking_for_max_y = false;
        looking_for_min_y = true;
        max_y = pos.y();
      }
    }
  }
  if (first_was_max_x && looking_for_min_x) {
    if (max_x - initial_x > threshold) {
      total++;
    } else {
      total--;
    }
  } else if (!first_was_max_x && looking_for_max_x) {
    if (initial_x - min_x > threshold) {
      total++;
    } else {
      total--;
    }
  }
  if (first_was_max_y && looking_for_min_y) {
    if (max_y - initial_y > threshold) {
      total++;
    } else {
      total--;
    }
  } else if (!first_was_max_y && looking_for_max_y) {
    if (initial_y - min_y > threshold) {
      total++;
    } else {
      total--;
    }
  }

  return total;
}