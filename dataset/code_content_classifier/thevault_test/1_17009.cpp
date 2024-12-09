TEST(DnsResponseWriteTest, AAAAQuestionAndCnameAnswer) {
  const std::string kName = "www.example.com";
  std::string dns_name;
  ASSERT_TRUE(DNSDomainFromDot(kName, &dns_name));

  DnsResourceRecord answer;
  answer.name = kName;
  answer.type = dns_protocol::kTypeCNAME;
  answer.klass = dns_protocol::kClassIN;
  answer.ttl = 120;  // 120 seconds.
  answer.SetOwnedRdata(dns_name);
  std::vector<DnsResourceRecord> answers(1, answer);

  base::Optional<DnsQuery> query(base::in_place, 114 /* id */, dns_name,
                                 dns_protocol::kTypeAAAA);

  DnsResponse response(114 /* response_id */, true /* is_authoritative*/,
                       answers, {} /* authority_records */,
                       {} /* additional records */, query);

  EXPECT_TRUE(response.IsValid());
}