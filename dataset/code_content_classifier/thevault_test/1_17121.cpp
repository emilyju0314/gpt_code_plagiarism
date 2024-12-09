void DeserializeExpectCTData(const base::Value& ct_list,
                             TransportSecurityState* state) {
  if (!ct_list.is_list())
    return;
  bool partition_by_nik = base::FeatureList::IsEnabled(
      features::kPartitionExpectCTStateByNetworkIsolationKey);

  const base::Time current_time(base::Time::Now());

  for (const base::Value& ct_entry : ct_list.GetList()) {
    if (!ct_entry.is_dict())
      continue;

    const std::string* hostname = ct_entry.FindStringKey(kHostname);
    const base::Value* network_isolation_key_value =
        ct_entry.FindKey(kNetworkIsolationKey);
    base::Optional<double> expect_ct_last_observed =
        ct_entry.FindDoubleKey(kExpectCTObserved);
    base::Optional<double> expect_ct_expiry =
        ct_entry.FindDoubleKey(kExpectCTExpiry);
    base::Optional<bool> expect_ct_enforce =
        ct_entry.FindBoolKey(kExpectCTEnforce);
    const std::string* expect_ct_report_uri =
        ct_entry.FindStringKey(kExpectCTReportUri);

    if (!hostname || !network_isolation_key_value ||
        !expect_ct_last_observed.has_value() || !expect_ct_expiry.has_value() ||
        !expect_ct_enforce.has_value() || !expect_ct_report_uri) {
      continue;
    }

    TransportSecurityState::ExpectCTState expect_ct_state;
    expect_ct_state.last_observed =
        base::Time::FromDoubleT(*expect_ct_last_observed);
    expect_ct_state.expiry = base::Time::FromDoubleT(*expect_ct_expiry);
    expect_ct_state.enforce = *expect_ct_enforce;

    GURL report_uri(*expect_ct_report_uri);
    if (report_uri.is_valid())
      expect_ct_state.report_uri = report_uri;

    if (expect_ct_state.expiry < current_time ||
        (!expect_ct_state.enforce && expect_ct_state.report_uri.is_empty())) {
      continue;
    }

    std::string hashed = ExternalStringToHashedDomain(*hostname);
    if (hashed.empty())
      continue;

    NetworkIsolationKey network_isolation_key;
    if (!NetworkIsolationKey::FromValue(*network_isolation_key_value,
                                        &network_isolation_key)) {
      continue;
    }

    // If Expect-CT is not being partitioned by NetworkIsolationKey, but
    // |network_isolation_key| is not empty, drop the entry, to avoid ambiguity
    // and favor entries that were saved with an empty NetworkIsolationKey.
    if (!partition_by_nik && !network_isolation_key.IsEmpty())
      continue;

    state->AddOrUpdateEnabledExpectCTHosts(hashed, network_isolation_key,
                                           expect_ct_state);
  }
}