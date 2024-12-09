TEST_F(MultiThreadedCertVerifierTest, DeleteVerifier) {
  base::FilePath certs_dir = GetTestCertsDirectory();
  scoped_refptr<X509Certificate> test_cert(
      ImportCertFromFile(certs_dir, "ok_cert.pem"));
  ASSERT_NE(static_cast<X509Certificate*>(nullptr), test_cert.get());

  int error;
  CertVerifyResult verify_result;
  std::unique_ptr<CertVerifier::Request> request;

  error = verifier_->Verify(
      CertVerifier::RequestParams(test_cert, "www.example.com", 0,
                                  /*ocsp_response=*/std::string(),
                                  /*sct_list=*/std::string()),
      &verify_result, base::BindOnce(&FailTest), &request, NetLogWithSource());
  ASSERT_THAT(error, IsError(ERR_IO_PENDING));
  ASSERT_TRUE(request);
  verifier_.reset();

  RunUntilIdle();
}