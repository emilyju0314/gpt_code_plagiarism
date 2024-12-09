TEST_F(CoalescingCertVerifierTest, DoesNotJoinAfterConfigChange) {
  scoped_refptr<X509Certificate> test_cert(
      ImportCertFromFile(GetTestCertsDirectory(), "ok_cert.pem"));
  ASSERT_TRUE(test_cert);

  base::HistogramTester histograms;

  CertVerifyResult fake_result;
  fake_result.verified_cert = test_cert;

  std::unique_ptr<MockCertVerifier> mock_verifier_owner =
      std::make_unique<MockCertVerifier>();
  MockCertVerifier* mock_verifier = mock_verifier_owner.get();
  mock_verifier->set_async(true);  // Always complete via PostTask
  mock_verifier->AddResultForCert(test_cert, fake_result, OK);

  CoalescingCertVerifier verifier(std::move(mock_verifier_owner));

  CertVerifier::Config config1;
  verifier.SetConfig(config1);

  CertVerifier::RequestParams request_params(test_cert, "www.example.com", 0,
                                             /*ocsp_response=*/std::string(),
                                             /*sct_list=*/std::string());

  CertVerifyResult result1, result2;
  TestCompletionCallback callback1, callback2;
  std::unique_ptr<CertVerifier::Request> request1, request2;

  // Start an (asynchronous) initial request.
  int error = verifier.Verify(request_params, &result1, callback1.callback(),
                              &request1, NetLogWithSource());
  ASSERT_THAT(error, IsError(ERR_IO_PENDING));
  EXPECT_TRUE(request1);

  // Change the configuration, and change the result to to simulate the
  // configuration change affecting behavior.
  CertVerifier::Config config2;
  config2.enable_rev_checking = !config1.enable_rev_checking;
  verifier.SetConfig(config2);
  mock_verifier->ClearRules();
  mock_verifier->AddResultForCert(test_cert, fake_result, ERR_CERT_REVOKED);

  // Start a second request; this should not join the first request, as the
  // config is different.
  error = verifier.Verify(request_params, &result2, callback2.callback(),
                          &request2, NetLogWithSource());
  ASSERT_THAT(error, IsError(ERR_IO_PENDING));
  EXPECT_TRUE(request2);

  // Ensure a total of two requests were started, and neither were joined.
  EXPECT_EQ(2u, verifier.requests_for_testing());
  EXPECT_EQ(0u, verifier.inflight_joins_for_testing());

  // Make sure both results completed.
  EXPECT_THAT(callback1.WaitForResult(), IsOk());
  EXPECT_THAT(callback2.WaitForResult(), IsError(ERR_CERT_REVOKED));

  // There should have been two separate Jobs.
  histograms.ExpectTotalCount("Net.CertVerifier_Job_Latency", 2);
  histograms.ExpectTotalCount("Net.CertVerifier_First_Job_Latency", 1);
}