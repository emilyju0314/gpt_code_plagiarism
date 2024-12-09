void DeserializeSTSData(const base::Value& sts_list,
                        TransportSecurityState* state) {
  if (!sts_list.is_list())
    return;

  base::Time current_time(base::Time::Now());

  for (const base::Value& sts_entry : sts_list.GetList()) {
    if (!sts_entry.is_dict())
      continue;

    const std::string* hostname = sts_entry.FindStringKey(kHostname);
    base::Optional<bool> sts_include_subdomains =
        sts_entry.FindBoolKey(kStsIncludeSubdomains);
    base::Optional<double> sts_observed = sts_entry.FindDoubleKey(kStsObserved);
    base::Optional<double> expiry = sts_entry.FindDoubleKey(kExpiry);
    const std::string* mode = sts_entry.FindStringKey(kMode);

    if (!hostname || !sts_include_subdomains.has_value() ||
        !sts_observed.has_value() || !expiry.has_value() || !mode) {
      continue;
    }

    TransportSecurityState::STSState sts_state;
    sts_state.include_subdomains = *sts_include_subdomains;
    sts_state.last_observed = base::Time::FromDoubleT(*sts_observed);
    sts_state.expiry = base::Time::FromDoubleT(*expiry);

    if (*mode == kForceHTTPS) {
      sts_state.upgrade_mode =
          TransportSecurityState::STSState::MODE_FORCE_HTTPS;
    } else if (*mode == kDefault) {
      sts_state.upgrade_mode = TransportSecurityState::STSState::MODE_DEFAULT;
    } else {
      continue;
    }

    if (sts_state.expiry < current_time || !sts_state.ShouldUpgradeToSSL())
      continue;

    std::string hashed = ExternalStringToHashedDomain(*hostname);
    if (hashed.empty())
      continue;

    state->AddOrUpdateEnabledSTSHosts(hashed, sts_state);
  }
}