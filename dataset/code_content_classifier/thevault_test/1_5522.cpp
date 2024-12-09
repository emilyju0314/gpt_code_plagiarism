common::Status CopyInputsAcrossDevices(const SessionState& session_state,
                                       const NameMLValMap& orig_feeds,
                                       NameMLValMap& new_feeds) {
  for (auto& pair : orig_feeds) {
    MLValue new_mlvalue;
    auto& input_name = pair.first;
    auto& orig_mlvalue = pair.second;
    ORT_RETURN_IF_ERROR(CopyOneInputAcrossDevices(session_state, input_name, orig_mlvalue, new_mlvalue));
    new_feeds[input_name] = new_mlvalue;
  }

  return Status::OK();
}