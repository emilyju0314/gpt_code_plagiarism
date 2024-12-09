TEST_F(HttpResponseInfoTest, EmptyDnsAliases) {
  response_info_.dns_aliases = {};
  net::HttpResponseInfo restored_response_info;
  PickleAndRestore(response_info_, &restored_response_info);
  EXPECT_TRUE(restored_response_info.dns_aliases.empty());
}