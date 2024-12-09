bool TFNetwork::DeSerialize(TFile *fp) {
  std::vector<char> data;
  if (!fp->DeSerialize(data))
    return false;
  if (!model_proto_.ParseFromArray(&data[0], data.size())) {
    return false;
  }
  return InitFromProto();
}