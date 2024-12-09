shash::Any SignatureManager::MkFromFingerprint(const std::string &fingerprint) {
  string convert;
  for (unsigned i = 0; i < fingerprint.length(); ++i) {
    if ((fingerprint[i] == ' ') || (fingerprint[i] == '\t') ||
        (fingerprint[i] == '#'))
    {
      break;
    }
    if (fingerprint[i] != ':')
      convert.push_back(tolower(fingerprint[i]));
  }

  return shash::MkFromHexPtr(shash::HexPtr(convert));
}