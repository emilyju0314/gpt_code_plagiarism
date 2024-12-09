base::Value SerializeExpectCTData(TransportSecurityState* state) {
  base::Value ct_list(base::Value::Type::LIST);

  if (!IsDynamicExpectCTEnabled())
    return ct_list;

  TransportSecurityState::ExpectCTStateIterator expect_ct_iterator(*state);
  for (; expect_ct_iterator.HasNext(); expect_ct_iterator.Advance()) {
    const TransportSecurityState::ExpectCTState& expect_ct_state =
        expect_ct_iterator.domain_state();

    base::Value ct_entry(base::Value::Type::DICTIONARY);

    base::Value network_isolation_key_value;
    // Don't serialize entries with transient NetworkIsolationKeys.
    if (!expect_ct_iterator.network_isolation_key().ToValue(
            &network_isolation_key_value)) {
      continue;
    }
    ct_entry.SetKey(kNetworkIsolationKey,
                    std::move(network_isolation_key_value));

    ct_entry.SetStringKey(
        kHostname, HashedDomainToExternalString(expect_ct_iterator.hostname()));
    ct_entry.SetDoubleKey(kExpectCTObserved,
                          expect_ct_state.last_observed.ToDoubleT());
    ct_entry.SetDoubleKey(kExpectCTExpiry, expect_ct_state.expiry.ToDoubleT());
    ct_entry.SetBoolKey(kExpectCTEnforce, expect_ct_state.enforce);
    ct_entry.SetStringKey(kExpectCTReportUri,
                          expect_ct_state.report_uri.spec());

    ct_list.Append(std::move(ct_entry));
  }

  return ct_list;
}