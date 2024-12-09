bool DeserializeObsoleteExpectCTState(
    const base::Value* parsed,
    TransportSecurityState::ExpectCTState* state) {
  const base::Value* expect_ct_subdictionary =
      parsed->FindDictKey(kExpectCTSubdictionary);
  if (!expect_ct_subdictionary) {
    // Expect-CT data is not required, so this item is not malformed.
    return true;
  }
  base::Optional<double> observed =
      expect_ct_subdictionary->FindDoubleKey(kExpectCTObserved);
  base::Optional<double> expiry =
      expect_ct_subdictionary->FindDoubleKey(kExpectCTExpiry);
  base::Optional<bool> enforce =
      expect_ct_subdictionary->FindBoolKey(kExpectCTEnforce);
  const std::string* report_uri_str =
      expect_ct_subdictionary->FindStringKey(kExpectCTReportUri);

  // If an Expect-CT subdictionary is present, it must have the required keys.
  if (!observed.has_value() || !expiry.has_value() || !enforce.has_value())
    return false;

  state->last_observed = base::Time::FromDoubleT(*observed);
  state->expiry = base::Time::FromDoubleT(*expiry);
  state->enforce = *enforce;
  if (report_uri_str) {
    GURL report_uri(*report_uri_str);
    if (report_uri.is_valid())
      state->report_uri = report_uri;
  }
  return true;
}