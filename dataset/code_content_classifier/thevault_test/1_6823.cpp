void TBrateLimitor::adjustRate() {
  // pay the penalty
  adjustScore(-1);

  double rate = token_rate;
  if (p_score >= n_score)
    rate = token_rate * (1 + 0.2);
  else 
    rate = token_rate * (1 - 0.2);

  setRate(rate);
}