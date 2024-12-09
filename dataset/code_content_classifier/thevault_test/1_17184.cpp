TEST_F(CoalescingCertVerifierTest, SyncCompletion) {
  scoped_refptr<X509Certificate> test_cert(
      ImportCertFromFile(GetTestCertsDirectory(), "ok_cert.pem"));
  ASSERT_TRUE(test_cert);

  CertVerifyResult fake_result;
  fake_result.verified_cert = test_cert;

  std::unique_ptr<MockCertVerifier> mock_verifier_owner =
      std::make_unique<MockCertVerifier>();
  MockCertVerifier* mock_verifier = mock_verifier_owner.get();
  mock_verifier->set_async(false);  // Force sync completion.
  mock_verifier->AddResultForCert(test_cert, fake_result, OK);

  CoalescingCertVerifier verifier(std::move(mock_verifier_owner));

  CertVerifier::RequestParams request_params(test_cert, "www.example.com", 0,
                                             /*ocsp_response=*/std::string(),
                                             /*sct_list=*/std::string());

  CertVerifyResult result1, result2;
  TestCompletionCallback callback1, callback2;
  std::unique_ptr<CertVerifier::Request> request1, request2;

  // Start an (asynchronous) initial request.
  int error = verifier.Verify(request_params, &result1, callback1.callback(),
                              &request1, NetLogWithSource());
  ASSERT_THAT(error, IsOk());
  ASSERT_FALSE(request1);
  ASSERT_TRUE(result1.verified_cert);
}