TEST(CertIssuerSourceAiaTest, NoAia) {
  scoped_refptr<ParsedCertificate> cert;
  ASSERT_TRUE(ReadTestCert("target_no_aia.pem", &cert));

  // No methods on |mock_fetcher| should be called.
  auto mock_fetcher = base::MakeRefCounted<StrictMock<MockCertNetFetcher>>();
  CertIssuerSourceAia aia_source(mock_fetcher);
  std::unique_ptr<CertIssuerSource::Request> request;
  aia_source.AsyncGetIssuersOf(cert.get(), &request);
  EXPECT_EQ(nullptr, request);
}