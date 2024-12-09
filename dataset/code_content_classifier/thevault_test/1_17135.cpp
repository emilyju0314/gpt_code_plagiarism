TEST(CertIssuerSourceAiaTest, FileAia) {
  scoped_refptr<ParsedCertificate> cert;
  ASSERT_TRUE(ReadTestCert("target_file_aia.pem", &cert));

  auto mock_fetcher = base::MakeRefCounted<StrictMock<MockCertNetFetcher>>();
  EXPECT_CALL(*mock_fetcher, FetchCaIssuers(GURL("file:///dev/null"), _, _))
      .WillOnce(Return(ByMove(CreateMockRequest(ERR_DISALLOWED_URL_SCHEME))));

  CertIssuerSourceAia aia_source(mock_fetcher);
  std::unique_ptr<CertIssuerSource::Request> cert_source_request;
  aia_source.AsyncGetIssuersOf(cert.get(), &cert_source_request);
  ASSERT_NE(nullptr, cert_source_request);

  // No results.
  ParsedCertificateList result_certs;
  cert_source_request->GetNext(&result_certs);
  EXPECT_TRUE(result_certs.empty());
}