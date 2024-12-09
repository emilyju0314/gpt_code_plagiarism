TEST_F(HttpResponseInfoTest, PeerSignatureAlgorithm) {
  response_info_.ssl_info.cert =
      ImportCertFromFile(GetTestCertsDirectory(), "ok_cert.pem");
  response_info_.ssl_info.peer_signature_algorithm =
      0x0804;  // rsa_pss_rsae_sha256
  net::HttpResponseInfo restored_response_info;
  PickleAndRestore(response_info_, &restored_response_info);
  EXPECT_EQ(0x0804, restored_response_info.ssl_info.peer_signature_algorithm);
}