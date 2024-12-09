TEST(URLParse, TypicalURLParseCanon) {
  url::Parsed parsed1;
  url::Parsed parsed2;
  url::Parsed parsed3;

  base::PerfTimeLogger canon_timer("Typical_Parse_Canon_AMillion");
  url::Parsed out_parsed;
  url::RawCanonOutput<1024> output;
  for (int i = 0; i < 333333; i++) {  // divide by 3 so we get 1M
    url::ParseStandardURL(kTypicalUrl1.data(), kTypicalUrl1.size(), &parsed1);
    output.set_length(0);
    url::CanonicalizeStandardURL(
        kTypicalUrl1.data(), kTypicalUrl1.size(), parsed1,
        url::SCHEME_WITH_HOST_PORT_AND_USER_INFORMATION, nullptr, &output,
        &out_parsed);

    url::ParseStandardURL(kTypicalUrl2.data(), kTypicalUrl2.size(), &parsed2);
    output.set_length(0);
    url::CanonicalizeStandardURL(
        kTypicalUrl2.data(), kTypicalUrl2.size(), parsed2,
        url::SCHEME_WITH_HOST_PORT_AND_USER_INFORMATION, nullptr, &output,
        &out_parsed);

    url::ParseStandardURL(kTypicalUrl3.data(), kTypicalUrl3.size(), &parsed3);
    output.set_length(0);
    url::CanonicalizeStandardURL(
        kTypicalUrl3.data(), kTypicalUrl3.size(), parsed3,
        url::SCHEME_WITH_HOST_PORT_AND_USER_INFORMATION, nullptr, &output,
        &out_parsed);
  }
  canon_timer.Done();
}