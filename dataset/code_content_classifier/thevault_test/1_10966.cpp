bool FullyConnected::Serialize(TFile *fp) const {
  if (!Network::Serialize(fp)) {
    return false;
  }
  if (!weights_.Serialize(IsTraining(), fp)) {
    return false;
  }
  return true;
}