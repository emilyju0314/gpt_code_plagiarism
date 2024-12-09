bool TFNetwork::Serialize(TFile *fp) const {
  if (!Network::Serialize(fp))
    return false;
  std::string proto_str;
  model_proto_.SerializeToString(&proto_str);
  // TODO: optimize and avoid copy from proto_str to data.
  std::vector<char> data(proto_str.size());
  memcpy(&data[0], proto_str.data(), proto_str.size());
  return fp->Serialize(data);
}