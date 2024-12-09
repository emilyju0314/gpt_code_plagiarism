bool BandwidthSmoother::Sample(uint32_t sample_time, int bandwidth) {
  if (bandwidth < 0) {
    return false;
  }

  accumulator_.AddSample(bandwidth);

  if (accumulator_.count() < static_cast<size_t>(
          accumulator_.max_count() * min_sample_count_percent_)) {
    // We have not collected enough samples yet.
    return false;
  }

  // Replace bandwidth with the mean of sampled bandwidths.
  const int mean_bandwidth = static_cast<int>(accumulator_.ComputeMean());

  if (mean_bandwidth < bandwidth_estimation_) {
    time_at_last_change_ = sample_time;
    bandwidth_estimation_ = mean_bandwidth;
    return true;
  }

  const int old_bandwidth_estimation = bandwidth_estimation_;
  const double increase_threshold_d = percent_increase_ * bandwidth_estimation_;
  if (increase_threshold_d > INT_MAX) {
    // If bandwidth goes any higher we would overflow.
    return false;
  }

  const int increase_threshold = static_cast<int>(increase_threshold_d);
  if (mean_bandwidth < increase_threshold) {
    time_at_last_change_ = sample_time;
    // The value of bandwidth_estimation remains the same if we don't exceed
    // percent_increase_ * bandwidth_estimation_ for at least
    // time_between_increase_ time.
  } else if (sample_time >= time_at_last_change_ + time_between_increase_) {
    time_at_last_change_ = sample_time;
    if (increase_threshold == 0) {
      // Bandwidth_estimation_ must be zero. Assume a jump from zero to a
      // positive bandwidth means we have regained connectivity.
      bandwidth_estimation_ = mean_bandwidth;
    } else {
      bandwidth_estimation_ = increase_threshold;
    }
  }
  // Else don't make a change.

  return old_bandwidth_estimation != bandwidth_estimation_;
}