void EWdetectorB::computeDropP() {
  double p = 0;

  if (alarm) {
    // Compute the dropping probability as a linear function of current rate
    //  p is computed towards the current measurement.
    p = 1;
    if (cur_rate)
      p = (avg_rate - cur_rate) * adjustor / cur_rate;
    
    // p could be greater than 1
    if (p > 1)
      p = 1;
    // p could also be negative
    if (p < 0)
      p = 0;
    
    // Compute the actual drop probability
    drop_p = ALPHA * drop_p + (1 - ALPHA) * p;    
    // adjust drop_p
    if (drop_p < EW_MIN_DROP_P)
      drop_p = EW_MIN_DROP_P;
    if (drop_p > EW_MAX_DROP_P)
      drop_p = EW_MAX_DROP_P;
  } else {
    // Fade out the drop_p when no alarm
    if (drop_p > 0) {
      if (drop_p <= EW_MIN_DROP_P)
        drop_p = 0;
      else {
        drop_p = ALPHA * drop_p;
      }
    }
  }
}