TEST(CertIssuerSourceAiaTest, OneAiaParseError) {
  scoped_refptr<ParsedCertificate> cert;
  ASSERT_TRUE(ReadTestCert("target_one_aia.pem", &cert));

  scoped_refptr<StrictMock<MockCertNetFetcher>> mock_fetcher(
      new StrictMock<MockCertNetFetcher>());

  // HTTP request returns invalid certificate data.
  EXPECT_CALL(*mock_fetcher,
              FetchCaIssuers(GURL("http://url-for-aia/I.cer"), _, _))
      .WillOnce(Return(
          ByMove(CreateMockRequest(std::vector<uint8_t>({1, 2, 3, 4, 5})))));

  CertIssuerSourceAia aia_source(mock_fetcher);
  std::unique_ptr<CertIssuerSource::Request> cert_source_request;
  aia_source.AsyncGetIssuersOf(cert.get(), &cert_source_request);
  ASSERT_NE(nullptr, cert_source_request);

  // No results.
  ParsedCertificateList result_certs;
  cert_source_request->GetNext(&result_certs);
  ASSERT_EQ(0u, result_certs.size());
}