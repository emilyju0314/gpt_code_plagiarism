bool Network::Serialize(TFile *fp) const {
  int8_t data = NT_NONE;
  if (!fp->Serialize(&data)) {
    return false;
  }
  std::string type_name = kTypeNames[type_];
  if (!fp->Serialize(type_name)) {
    return false;
  }
  data = training_;
  if (!fp->Serialize(&data)) {
    return false;
  }
  data = needs_to_backprop_;
  if (!fp->Serialize(&data)) {
    return false;
  }
  if (!fp->Serialize(&network_flags_)) {
    return false;
  }
  if (!fp->Serialize(&ni_)) {
    return false;
  }
  if (!fp->Serialize(&no_)) {
    return false;
  }
  if (!fp->Serialize(&num_weights_)) {
    return false;
  }
  uint32_t length = name_.length();
  if (!fp->Serialize(&length)) {
    return false;
  }
  return fp->Serialize(name_.c_str(), length);
}