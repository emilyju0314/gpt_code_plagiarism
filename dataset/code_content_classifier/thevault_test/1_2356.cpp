void SampleBundle::Upload(DockyardProxy* dockyard_proxy) {
  DockyardProxyStatus status =
      dockyard_proxy->SendSamples(int_sample_list_, string_sample_list_);
  if (status != DockyardProxyStatus::OK) {
    FXL_LOG(ERROR) << DockyardErrorString("SendSamples", status)
                   << " Sample information will be missing";
  }

  if (FXL_VLOG_IS_ON(2)) {
    for (const auto& int_sample : int_sample_list_) {
      FXL_VLOG(2) << int_sample.first << ": " << int_sample.second;
    }
    for (const auto& string_sample : string_sample_list_) {
      FXL_VLOG(2) << string_sample.first << ": " << string_sample.second;
    }
  }

  int_sample_list_.clear();
  string_sample_list_.clear();
}