TEST_F(CertAndCTVerifierTest, CertAndCTDetailsFilled_Async) {
  base::FilePath certs_dir = GetTestCertsDirectory();
  scoped_refptr<X509Certificate> test_cert(
      ImportCertFromFile(certs_dir, "ok_cert.pem"));
  ASSERT_TRUE(test_cert.get());

  // Mock the cert verification and CT verification results.
  CertVerifyResult mock_result;
  mock_result.cert_status = OK;
  mock_result.verified_cert = test_cert;
  auto cert_verifier = std::make_unique<MockCertVerifier>();
  cert_verifier->AddResultForCert(test_cert, mock_result, OK);
  cert_verifier->set_async(true);

  scoped_refptr<ct::SignedCertificateTimestamp> sct;
  ct::GetX509CertSCT(&sct);
  SignedCertificateTimestampAndStatus sct_and_status(sct, ct::SCT_STATUS_OK);
  SignedCertificateTimestampAndStatusList sct_list{sct_and_status};
  auto ct_verifier = std::make_unique<FakeCTVerifier>();
  ct_verifier->set_scts(sct_list);

  CertAndCTVerifier cert_and_ct_verifier(std::move(cert_verifier),
                                         std::move(ct_verifier));

  CertVerifyResult verify_result;
  TestCompletionCallback callback;
  std::unique_ptr<CertVerifier::Request> request;

  int result = callback.GetResult(cert_and_ct_verifier.Verify(
      CertVerifier::RequestParams(test_cert, "www.example.com", 0,
                                  /*ocsp_response=*/std::string(),
                                  /*sct_list=*/std::string()),
      &verify_result, callback.callback(), &request, NetLogWithSource()));
  EXPECT_THAT(result, IsOk());
  ASSERT_EQ(1u, verify_result.scts.size());
  EXPECT_EQ(ct::SCT_STATUS_OK, verify_result.scts[0].status);
}