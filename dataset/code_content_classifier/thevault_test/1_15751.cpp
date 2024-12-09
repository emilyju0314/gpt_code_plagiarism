static bool VerifyWhitelist(const unsigned char *whitelist,
                            const unsigned whitelist_size,
                            const string &expected_repository)
{
  const string fingerprint = signature::FingerprintCertificate();
  if (fingerprint == "") {
    LogCvmfs(kLogSignature, kLogDebug, "invalid fingerprint");
    return false;
  }
  LogCvmfs(kLogSignature, kLogDebug,
           "checking certificate with fingerprint %s against whitelist",
           fingerprint.c_str());

  time_t local_timestamp = time(NULL);
  string line;
  unsigned payload_bytes = 0;

  // Check timestamp (UTC), ignore issue date (legacy)
  line = GetLineMem(reinterpret_cast<const char *>(whitelist), whitelist_size);
  if (line.length() != 14) {
    LogCvmfs(kLogSignature, kLogDebug, "invalid timestamp format");
    return false;
  }
  payload_bytes += 15;

  // Expiry date
  line = GetLineMem(reinterpret_cast<const char *>(whitelist)+payload_bytes,
                    whitelist_size-payload_bytes);
  if (line.length() != 15) {
    LogCvmfs(kLogSignature, kLogDebug, "invalid timestamp format");
    return false;
  }
  struct tm tm_wl;
  memset(&tm_wl, 0, sizeof(struct tm));
  tm_wl.tm_year = String2Int64(line.substr(1, 4))-1900;
  tm_wl.tm_mon = String2Int64(line.substr(5, 2)) - 1;
  tm_wl.tm_mday = String2Int64(line.substr(7, 2));
  tm_wl.tm_hour = String2Int64(line.substr(9, 2));
  tm_wl.tm_min = tm_wl.tm_sec = 0;  // exact on hours level
  time_t timestamp = timegm(&tm_wl);
  LogCvmfs(kLogSignature, kLogDebug,
           "whitelist UTC expiry timestamp in localtime: %s",
           StringifyTime(timestamp, false).c_str());
  if (timestamp < 0) {
    LogCvmfs(kLogSignature, kLogDebug, "invalid timestamp");
    return false;
  }
  LogCvmfs(kLogSignature, kLogDebug,  "local time: %s",
           StringifyTime(local_timestamp, true).c_str());
  if (local_timestamp > timestamp) {
    LogCvmfs(kLogSignature, kLogDebug | kLogSyslogErr,
             "whitelist lifetime verification failed, expired");
    return false;
  }
  payload_bytes += 16;

  // Check repository name
  line = GetLineMem(reinterpret_cast<const char *>(whitelist)+payload_bytes,
                    whitelist_size-payload_bytes);
  if ((expected_repository != "") && ("N" + expected_repository != line)) {
    LogCvmfs(kLogSignature, kLogDebug | kLogSyslogErr,
             "repository name on the whitelist does not match "
             "(found %s, expected %s)",
             line.c_str(), expected_repository.c_str());
    return false;
  }
  payload_bytes += line.length() + 1;

  // Search the fingerprint
  bool found = false;
  do {
    line = GetLineMem(reinterpret_cast<const char *>(whitelist)+payload_bytes,
                      whitelist_size-payload_bytes);
    if (line == "--") break;
    if (line.substr(0, 59) == fingerprint)
      found = true;
    payload_bytes += line.length() + 1;
  } while (payload_bytes < whitelist_size);
  payload_bytes += line.length() + 1;

  if (!found) {
    LogCvmfs(kLogSignature, kLogDebug,
             "the certificate's fingerprint is not on the whitelist");
    return false;
  }

  // Check local blacklist
  vector<string> blacklisted_certificates =
    signature::GetBlacklistedCertificates();
  for (unsigned i = 0; i < blacklisted_certificates.size(); ++i) {
    if (blacklisted_certificates[i].substr(0, 59) == fingerprint) {
      LogCvmfs(kLogSignature, kLogDebug | kLogSyslogErr,
               "blacklisted fingerprint (%s)", fingerprint.c_str());
      return false;
    }
  }

  return true;
}