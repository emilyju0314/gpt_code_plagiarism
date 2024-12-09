TEST_F(NSSCertDatabaseChromeOSTest, ImportServerCert) {
  // Load test certs from disk.
  ScopedCERTCertificateList certs_1 = CreateCERTCertificateListFromFile(
      GetTestCertsDirectory(), "ok_cert.pem", X509Certificate::FORMAT_AUTO);
  ASSERT_EQ(1U, certs_1.size());

  ScopedCERTCertificateList certs_2 = CreateCERTCertificateListFromFile(
      GetTestCertsDirectory(), "2048-rsa-ee-by-2048-rsa-intermediate.pem",
      X509Certificate::FORMAT_AUTO);
  ASSERT_EQ(1U, certs_2.size());

  // Import one cert for each user.
  NSSCertDatabase::ImportCertFailureList failed;
  EXPECT_TRUE(
      db_1_->ImportServerCert(certs_1, NSSCertDatabase::TRUSTED_SSL, &failed));
  EXPECT_EQ(0U, failed.size());
  failed.clear();
  EXPECT_TRUE(
      db_2_->ImportServerCert(certs_2, NSSCertDatabase::TRUSTED_SSL, &failed));
  EXPECT_EQ(0U, failed.size());

  // Get cert list for each user.
  ScopedCERTCertificateList user_1_certlist;
  ScopedCERTCertificateList user_2_certlist;
  db_1_->ListCerts(
      base::BindOnce(&SwapCertLists, base::Unretained(&user_1_certlist)));
  db_2_->ListCerts(
      base::BindOnce(&SwapCertLists, base::Unretained(&user_2_certlist)));

  // Run the message loop so the observer notifications get processed and
  // lookups are completed.
  RunUntilIdle();
  // TODO(mattm): ImportServerCert doesn't actually cause any observers to
  // fire. Is that correct?
  EXPECT_EQ(0, db_changed_count_);

  EXPECT_TRUE(IsCertInCertificateList(certs_1[0].get(), user_1_certlist));
  EXPECT_FALSE(IsCertInCertificateList(certs_1[0].get(), user_2_certlist));

  EXPECT_TRUE(IsCertInCertificateList(certs_2[0].get(), user_2_certlist));
  EXPECT_FALSE(IsCertInCertificateList(certs_2[0].get(), user_1_certlist));
}