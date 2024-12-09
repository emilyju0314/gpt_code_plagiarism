void C_OUTLINE::ComputeBinaryOffsets() {
  delete[] offsets;
  offsets = new EdgeOffset[stepcount];
  // Count of the number of steps in each direction in the sliding window.
  int dir_counts[4];
  // Sum of the positions (y for a horizontal step, x for vertical) in each
  // direction in the sliding window.
  int pos_totals[4];
  memset(dir_counts, 0, sizeof(dir_counts));
  memset(pos_totals, 0, sizeof(pos_totals));
  ICOORD pos = start;
  ICOORD tail_pos = pos;
  // tail_pos is the trailing position, with the next point to be lost from
  // the window.
  tail_pos -= step(stepcount - 1);
  tail_pos -= step(stepcount - 2);
  // head_pos is the leading position, with the next point to be added to the
  // window.
  ICOORD head_pos = tail_pos;
  // Set up the initial window with 4 points in [-2, 2)
  for (int s = -2; s < 2; ++s) {
    increment_step(s, 1, &head_pos, dir_counts, pos_totals);
  }
  for (int s = 0; s < stepcount; pos += step(s++)) {
    // At step s, s in in the middle of [s-2, s+2].
    increment_step(s + 2, 1, &head_pos, dir_counts, pos_totals);
    int dir_index = chain_code(s);
    ICOORD step_vec = step(s);
    int best_diff = 0;
    int offset = 0;
    // Use only steps that have a count of >=2 OR the strong U-turn with a
    // single d and 2 at d-1 and 2 at d+1 (mod 4).
    if (dir_counts[dir_index] >= 2 ||
        (dir_counts[dir_index] == 1 && dir_counts[Modulo(dir_index - 1, 4)] == 2 &&
         dir_counts[Modulo(dir_index + 1, 4)] == 2)) {
      // Valid step direction.
      best_diff = dir_counts[dir_index];
      int edge_pos = step_vec.x() == 0 ? pos.x() : pos.y();
      // The offset proposes that the actual step should be positioned at
      // the mean position of the steps in the window of the same direction.
      // See ASCII art above.
      offset = pos_totals[dir_index] - best_diff * edge_pos;
    }
    offsets[s].offset_numerator = ClipToRange<int>(offset, -INT8_MAX, INT8_MAX);
    offsets[s].pixel_diff = ClipToRange<int>(best_diff, 0, UINT8_MAX);
    // The direction is just the vector from start to end of the window.
    FCOORD direction(head_pos.x() - tail_pos.x(), head_pos.y() - tail_pos.y());
    offsets[s].direction = direction.to_direction();
    increment_step(s - 2, -1, &tail_pos, dir_counts, pos_totals);
  }
}