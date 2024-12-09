TEST_F(MultiThreadedCertVerifierTest, DeleteVerifierCallbackOwnsResult) {
  base::FilePath certs_dir = GetTestCertsDirectory();
  scoped_refptr<X509Certificate> test_cert(
      ImportCertFromFile(certs_dir, "ok_cert.pem"));
  ASSERT_NE(static_cast<X509Certificate*>(nullptr), test_cert.get());

  int error;
  CertVerifyResult verify_result;
  std::unique_ptr<CertVerifyResultHelper> result_helper =
      std::make_unique<CertVerifyResultHelper>();
  CertVerifyResultHelper* result_helper_ptr = result_helper.get();
  CompletionOnceCallback callback = base::BindOnce(
      &CertVerifyResultHelper::FailTest, std::move(result_helper));

  error = verifier_->Verify(
      CertVerifier::RequestParams(test_cert, "www.example.com", 0,
                                  /*ocsp_response=*/std::string(),
                                  /*sct_list=*/std::string()),
      &verify_result, std::move(callback), &result_helper_ptr->request,
      NetLogWithSource());
  ASSERT_THAT(error, IsError(ERR_IO_PENDING));
  ASSERT_TRUE(result_helper_ptr->request);
  verifier_.reset();

  RunUntilIdle();
}