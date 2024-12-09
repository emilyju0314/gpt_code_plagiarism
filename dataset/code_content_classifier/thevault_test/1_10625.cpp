void FPCUTPT::assign(       // constructor
    FPCUTPT *cutpts,        // predecessors
    int16_t array_origin,   // start coord
    int16_t x,              // position
    bool faking,            // faking this one
    bool mid_cut,           // cheap cut.
    int16_t offset,         // dist to gap
    STATS *projection,      // vertical occupation
    float projection_scale, // scaling
    int16_t zero_count,     // official zero
    int16_t pitch,          // proposed pitch
    int16_t pitch_error     // allowed tolerance
) {
  int index;             // test index
  int balance_index;     // for balance factor
  int16_t balance_count; // ding factor
  int16_t r_index;       // test cut number
  FPCUTPT *segpt;        // segment point
  int32_t dist;          // from prev segment
  double sq_dist;        // squared distance
  double mean;           // mean pitch
  double total;          // total dists
  double factor;         // cost function
                         // half of pitch
  int16_t half_pitch = pitch / 2 - 1;
  uint32_t lead_flag; // new flag

  if (half_pitch > 31) {
    half_pitch = 31;
  } else if (half_pitch < 0) {
    half_pitch = 0;
  }
  lead_flag = 1 << half_pitch;

  back_balance = cutpts[x - 1 - array_origin].back_balance << 1;
  back_balance &= lead_flag + (lead_flag - 1);
  if (projection->pile_count(x) > zero_count) {
    back_balance |= 1;
  }
  fwd_balance = cutpts[x - 1 - array_origin].fwd_balance >> 1;
  if (projection->pile_count(x + half_pitch) > zero_count) {
    fwd_balance |= lead_flag;
  }

  xpos = x;
  cost = FLT_MAX;
  pred = nullptr;
  faked = faking;
  terminal = false;
  region_index = 0;
  fake_count = INT16_MAX;
  for (index = x - pitch - pitch_error; index <= x - pitch + pitch_error; index++) {
    if (index >= array_origin) {
      segpt = &cutpts[index - array_origin];
      dist = x - segpt->xpos;
      if (!segpt->terminal && segpt->fake_count < INT16_MAX) {
        balance_count = 0;
        if (textord_balance_factor > 0) {
          if (textord_fast_pitch_test) {
            lead_flag = back_balance ^ segpt->fwd_balance;
            balance_count = 0;
            while (lead_flag != 0) {
              balance_count++;
              lead_flag &= lead_flag - 1;
            }
          } else {
            for (balance_index = 0; index + balance_index < x - balance_index; balance_index++) {
              balance_count += (projection->pile_count(index + balance_index) <= zero_count) ^
                               (projection->pile_count(x - balance_index) <= zero_count);
            }
          }
          balance_count =
              static_cast<int16_t>(balance_count * textord_balance_factor / projection_scale);
        }
        r_index = segpt->region_index + 1;
        total = segpt->mean_sum + dist;
        balance_count += offset;
        sq_dist = dist * dist + segpt->sq_sum + balance_count * balance_count;
        mean = total / r_index;
        factor = mean - pitch;
        factor *= factor;
        factor += sq_dist / (r_index)-mean * mean;
        if (factor < cost && segpt->fake_count + faked <= fake_count) {
          cost = factor; // find least cost
          pred = segpt;  // save path
          mean_sum = total;
          sq_sum = sq_dist;
          fake_count = segpt->fake_count + faked;
          mid_cuts = segpt->mid_cuts + mid_cut;
          region_index = r_index;
        }
      }
    }
  }
}