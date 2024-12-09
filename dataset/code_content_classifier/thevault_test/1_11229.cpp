void UNICHARSET::set_black_and_whitelist(const char *blacklist,
                                         const char *whitelist,
                                         const char *unblacklist) {
  bool def_enabled = whitelist == nullptr || whitelist[0] == '\0';
  // Set everything to default
  for (auto &uc : unichars) {
    uc.properties.enabled = def_enabled;
  }
  if (!def_enabled) {
    // Enable the whitelist.
    std::vector<UNICHAR_ID> encoding;
    encode_string(whitelist, false, &encoding, nullptr, nullptr);
    for (auto it : encoding) {
      if (it != INVALID_UNICHAR_ID) {
        unichars[it].properties.enabled = true;
      }
    }
  }
  if (blacklist != nullptr && blacklist[0] != '\0') {
    // Disable the blacklist.
    std::vector<UNICHAR_ID> encoding;
    encode_string(blacklist, false, &encoding, nullptr, nullptr);
    for (auto it : encoding) {
      if (it != INVALID_UNICHAR_ID) {
        unichars[it].properties.enabled = false;
      }
    }
  }
  if (unblacklist != nullptr && unblacklist[0] != '\0') {
    // Re-enable the unblacklist.
    std::vector<UNICHAR_ID> encoding;
    encode_string(unblacklist, false, &encoding, nullptr, nullptr);
    for (auto it : encoding) {
      if (it != INVALID_UNICHAR_ID) {
        unichars[it].properties.enabled = true;
      }
    }
  }
}