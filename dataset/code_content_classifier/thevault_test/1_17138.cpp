TEST(CertIssuerSourceAiaTest, OneFileOneHttpAia) {
  scoped_refptr<ParsedCertificate> cert;
  ASSERT_TRUE(ReadTestCert("target_file_and_http_aia.pem", &cert));
  scoped_refptr<ParsedCertificate> intermediate_cert;
  ASSERT_TRUE(ReadTestCert("i2.pem", &intermediate_cert));

  auto mock_fetcher = base::MakeRefCounted<StrictMock<MockCertNetFetcher>>();

  EXPECT_CALL(*mock_fetcher, FetchCaIssuers(GURL("file:///dev/null"), _, _))
      .WillOnce(Return(ByMove(CreateMockRequest(ERR_DISALLOWED_URL_SCHEME))));

  EXPECT_CALL(*mock_fetcher,
              FetchCaIssuers(GURL("http://url-for-aia2/I2.foo"), _, _))
      .WillOnce(Return(
          ByMove(CreateMockRequest(CertDataVector(intermediate_cert.get())))));

  CertIssuerSourceAia aia_source(mock_fetcher);
  std::unique_ptr<CertIssuerSource::Request> cert_source_request;
  aia_source.AsyncGetIssuersOf(cert.get(), &cert_source_request);
  ASSERT_NE(nullptr, cert_source_request);

  ParsedCertificateList result_certs;
  cert_source_request->GetNext(&result_certs);
  ASSERT_EQ(1u, result_certs.size());
  ASSERT_EQ(result_certs.front()->der_cert(), intermediate_cert->der_cert());

  cert_source_request->GetNext(&result_certs);
  EXPECT_EQ(1u, result_certs.size());
}