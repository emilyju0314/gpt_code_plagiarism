void DPPoint::UpdateIfBetter(int64_t cost, int32_t steps, const DPPoint *prev, int32_t n,
                             int32_t sig_x, int64_t sig_xsq) {
  if (cost < total_cost_) {
    total_cost_ = cost;
    total_steps_ = steps;
    best_prev_ = prev;
    n_ = n;
    sig_x_ = sig_x;
    sig_xsq_ = sig_xsq;
  }
}