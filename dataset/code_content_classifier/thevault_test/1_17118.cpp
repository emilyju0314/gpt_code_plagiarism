base::Value SerializeSTSData(const TransportSecurityState* state) {
  base::Value sts_list(base::Value::Type::LIST);

  TransportSecurityState::STSStateIterator sts_iterator(*state);
  for (; sts_iterator.HasNext(); sts_iterator.Advance()) {
    const TransportSecurityState::STSState& sts_state =
        sts_iterator.domain_state();

    base::Value serialized(base::Value::Type::DICTIONARY);
    serialized.SetStringKey(
        kHostname, HashedDomainToExternalString(sts_iterator.hostname()));
    serialized.SetBoolKey(kStsIncludeSubdomains, sts_state.include_subdomains);
    serialized.SetDoubleKey(kStsObserved, sts_state.last_observed.ToDoubleT());
    serialized.SetDoubleKey(kExpiry, sts_state.expiry.ToDoubleT());

    switch (sts_state.upgrade_mode) {
      case TransportSecurityState::STSState::MODE_FORCE_HTTPS:
        serialized.SetStringKey(kMode, kForceHTTPS);
        break;
      case TransportSecurityState::STSState::MODE_DEFAULT:
        serialized.SetStringKey(kMode, kDefault);
        break;
    }

    sts_list.Append(std::move(serialized));
  }
  return sts_list;
}