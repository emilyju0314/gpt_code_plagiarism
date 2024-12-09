void UnicharCompress::SetupPassThrough(const UNICHARSET &unicharset) {
  std::vector<RecodedCharID> codes;
  for (unsigned u = 0; u < unicharset.size(); ++u) {
    RecodedCharID code;
    code.Set(0, u);
    codes.push_back(code);
  }
  if (!unicharset.has_special_codes()) {
    RecodedCharID code;
    code.Set(0, unicharset.size());
    codes.push_back(code);
  }
  SetupDirect(codes);
}