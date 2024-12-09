void FPCUTPT::setup(      // constructor
    FPCUTPT *cutpts,      // predecessors
    int16_t array_origin, // start coord
    STATS *projection,    // vertical occupation
    int16_t zero_count,   // official zero
    int16_t pitch,        // proposed pitch
    int16_t x,            // position
    int16_t offset        // dist to gap
) {
  // half of pitch
  int16_t half_pitch = pitch / 2 - 1;
  uint32_t lead_flag; // new flag
  int32_t ind;        // current position

  if (half_pitch > 31) {
    half_pitch = 31;
  } else if (half_pitch < 0) {
    half_pitch = 0;
  }
  lead_flag = 1 << half_pitch;

  pred = nullptr;
  mean_sum = 0;
  sq_sum = offset * offset;
  cost = sq_sum;
  faked = false;
  terminal = false;
  fake_count = 0;
  xpos = x;
  region_index = 0;
  mid_cuts = 0;
  if (x == array_origin) {
    back_balance = 0;
    fwd_balance = 0;
    for (ind = 0; ind <= half_pitch; ind++) {
      fwd_balance >>= 1;
      if (projection->pile_count(ind) > zero_count) {
        fwd_balance |= lead_flag;
      }
    }
  } else {
    back_balance = cutpts[x - 1 - array_origin].back_balance << 1;
    back_balance &= lead_flag + (lead_flag - 1);
    if (projection->pile_count(x) > zero_count) {
      back_balance |= 1;
    }
    fwd_balance = cutpts[x - 1 - array_origin].fwd_balance >> 1;
    if (projection->pile_count(x + half_pitch) > zero_count) {
      fwd_balance |= lead_flag;
    }
  }
}