TEST(CertIssuerSourceAiaTest, TwoAiaCompletedInSeriesFirstFails) {
  scoped_refptr<ParsedCertificate> cert;
  ASSERT_TRUE(ReadTestCert("target_two_aia.pem", &cert));
  scoped_refptr<ParsedCertificate> intermediate_cert2;
  ASSERT_TRUE(ReadTestCert("i2.pem", &intermediate_cert2));

  scoped_refptr<StrictMock<MockCertNetFetcher>> mock_fetcher(
      new StrictMock<MockCertNetFetcher>());

  // Request for I.cer completes first, but fails.
  EXPECT_CALL(*mock_fetcher,
              FetchCaIssuers(GURL("http://url-for-aia/I.cer"), _, _))
      .WillOnce(Return(ByMove(CreateMockRequest(ERR_INVALID_RESPONSE))));

  // Request for I2.foo succeeds.
  EXPECT_CALL(*mock_fetcher,
              FetchCaIssuers(GURL("http://url-for-aia2/I2.foo"), _, _))
      .WillOnce(Return(
          ByMove(CreateMockRequest(CertDataVector(intermediate_cert2.get())))));

  CertIssuerSourceAia aia_source(mock_fetcher);
  std::unique_ptr<CertIssuerSource::Request> cert_source_request;
  aia_source.AsyncGetIssuersOf(cert.get(), &cert_source_request);
  ASSERT_NE(nullptr, cert_source_request);

  // GetNext() should return intermediate_cert2.
  ParsedCertificateList result_certs;
  cert_source_request->GetNext(&result_certs);
  ASSERT_EQ(1u, result_certs.size());
  EXPECT_EQ(result_certs.front()->der_cert(), intermediate_cert2->der_cert());

  // No more results.
  result_certs.clear();
  cert_source_request->GetNext(&result_certs);
  EXPECT_EQ(0u, result_certs.size());
}