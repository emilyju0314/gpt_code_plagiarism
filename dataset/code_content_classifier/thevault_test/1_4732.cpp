bool GpuSubmissionTrack::TimerFilter(const TimerInfo& timer_info) const {
  if (IsCollapsed()) {
    std::string gpu_stage = string_manager_->Get(timer_info.user_data_key()).value_or("");
    return gpu_stage == kHwExecutionString;
  }
  return true;
}