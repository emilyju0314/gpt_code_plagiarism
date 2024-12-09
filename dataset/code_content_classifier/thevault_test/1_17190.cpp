TEST_F(CoalescingCertVerifierTest,
       DeleteFirstRequestBeforeCompletionStillCompletesSecondRequest) {
  scoped_refptr<X509Certificate> test_cert(
      ImportCertFromFile(GetTestCertsDirectory(), "ok_cert.pem"));
  ASSERT_TRUE(test_cert);

  CertVerifyResult fake_result;
  fake_result.verified_cert = test_cert;

  std::unique_ptr<MockCertVerifier> mock_verifier_owner =
      std::make_unique<MockCertVerifier>();
  MockCertVerifier* mock_verifier = mock_verifier_owner.get();
  mock_verifier->set_async(true);  // Always complete via PostTask
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
  ASSERT_THAT(error, IsError(ERR_IO_PENDING));
  EXPECT_TRUE(request1);

  // Start a second request; this should join the first request.
  error = verifier.Verify(request_params, &result2, callback2.callback(),
                          &request2, NetLogWithSource());
  ASSERT_THAT(error, IsError(ERR_IO_PENDING));
  EXPECT_TRUE(request2);

  // Ensure only one underlying verification was started.
  ASSERT_EQ(2u, verifier.requests_for_testing());
  ASSERT_EQ(1u, verifier.inflight_joins_for_testing());

  // Abandon the first request before it's completed.
  request1.reset();

  // Make sure the first request never completes / the callback is never
  // invoked, while the second request completes normally.
  EXPECT_THAT(callback2.WaitForResult(), IsOk());
  EXPECT_FALSE(callback1.have_result());

  // Simulate the second request going away during processing.
  request2.reset();

  // Flush any events, although there should not be any.
  RunUntilIdle();
  EXPECT_FALSE(callback1.have_result());
}