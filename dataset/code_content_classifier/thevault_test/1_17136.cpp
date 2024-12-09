TEST(CertIssuerSourceAiaTest, OneInvalidURL) {
  scoped_refptr<ParsedCertificate> cert;
  ASSERT_TRUE(ReadTestCert("target_invalid_url_aia.pem", &cert));

  auto mock_fetcher = base::MakeRefCounted<StrictMock<MockCertNetFetcher>>();
  CertIssuerSourceAia aia_source(mock_fetcher);
  std::unique_ptr<CertIssuerSource::Request> request;
  aia_source.AsyncGetIssuersOf(cert.get(), &request);
  EXPECT_EQ(nullptr, request);
}