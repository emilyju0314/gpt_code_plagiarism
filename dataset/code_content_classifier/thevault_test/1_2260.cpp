void AudioDeviceManager::Shutdown() {
  TRACE_DURATION("audio", "AudioDeviceManager::Shutdown");
  plug_detector_.Stop();

  std::vector<fit::promise<void>> device_promises;
  for (auto& [_, device] : devices_pending_init_) {
    device_promises.push_back(device->Shutdown());
  }
  devices_pending_init_.clear();

  for (auto& [_, device] : devices_) {
    device_promises.push_back(
        fit::join_promises(device->Shutdown(), device_settings_persistence_.FinalizeSettings(
                                                   *device->device_settings()))
            .and_then([](std::tuple<fit::result<void>, fit::result<void, zx_status_t>>& results)
                          -> fit::result<void> {
              FX_DCHECK(std::get<0>(results).is_ok());
              if (std::get<1>(results).is_error()) {
                return fit::error();
              }
              return fit::ok();
            }));
  }
  devices_.clear();

  fit::run_single_threaded(fit::join_promise_vector(std::move(device_promises)));
}