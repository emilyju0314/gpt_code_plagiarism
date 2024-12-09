TEST(ClientCertStoreNSSTest, BuildsCertificateChain) {
  base::test::TaskEnvironment task_environment;

  // Set up a test DB and import client_1.pem and client_1_ca.pem.
  crypto::ScopedTestNSSDB test_db;
  scoped_refptr<X509Certificate> client_1(ImportClientCertAndKeyFromFile(
      GetTestCertsDirectory(), "client_1.pem", "client_1.pk8", test_db.slot()));
  ASSERT_TRUE(client_1.get());
  scoped_refptr<X509Certificate> client_1_ca(
      ImportCertFromFile(GetTestCertsDirectory(), "client_1_ca.pem"));
  ASSERT_TRUE(client_1_ca.get());
  ASSERT_TRUE(ImportClientCertToSlot(client_1_ca, test_db.slot()));
  std::string pkcs8_key;
  ASSERT_TRUE(base::ReadFileToString(
      GetTestCertsDirectory().AppendASCII("client_1.pk8"), &pkcs8_key));

  std::unique_ptr<ClientCertStoreNSS> store(
      new ClientCertStoreNSS(ClientCertStoreNSS::PasswordDelegateFactory()));

  // These test keys are RSA keys.
  std::vector<uint16_t> expected = SSLPrivateKey::DefaultAlgorithmPreferences(
      EVP_PKEY_RSA, true /* supports PSS */);

  {
    // Request certificates matching B CA, |client_1|'s issuer.
    auto request = base::MakeRefCounted<SSLCertRequestInfo>();
    request->cert_authorities.push_back(std::string(
        reinterpret_cast<const char*>(kAuthority1DN), sizeof(kAuthority1DN)));

    ClientCertIdentityList selected_identities;
    base::RunLoop loop;
    store->GetClientCerts(
        *request.get(),
        base::BindOnce(SaveIdentitiesAndQuitCallback, &selected_identities,
                       loop.QuitClosure()));
    loop.Run();

    // The result be |client_1| with no intermediates.
    ASSERT_EQ(1u, selected_identities.size());
    scoped_refptr<X509Certificate> selected_cert =
        selected_identities[0]->certificate();
    EXPECT_TRUE(x509_util::CryptoBufferEqual(client_1->cert_buffer(),
                                             selected_cert->cert_buffer()));
    ASSERT_EQ(0u, selected_cert->intermediate_buffers().size());

    scoped_refptr<SSLPrivateKey> ssl_private_key;
    base::RunLoop key_loop;
    selected_identities[0]->AcquirePrivateKey(
        base::BindOnce(SavePrivateKeyAndQuitCallback, &ssl_private_key,
                       key_loop.QuitClosure()));
    key_loop.Run();

    ASSERT_TRUE(ssl_private_key);
    EXPECT_EQ(expected, ssl_private_key->GetAlgorithmPreferences());
    TestSSLPrivateKeyMatches(ssl_private_key.get(), pkcs8_key);
  }

  {
    // Request certificates matching C Root CA, |client_1_ca|'s issuer.
    auto request = base::MakeRefCounted<SSLCertRequestInfo>();
    request->cert_authorities.push_back(
        std::string(reinterpret_cast<const char*>(kAuthorityRootDN),
                    sizeof(kAuthorityRootDN)));

    ClientCertIdentityList selected_identities;
    base::RunLoop loop;
    store->GetClientCerts(
        *request.get(),
        base::BindOnce(SaveIdentitiesAndQuitCallback, &selected_identities,
                       loop.QuitClosure()));
    loop.Run();

    // The result be |client_1| with |client_1_ca| as an intermediate.
    ASSERT_EQ(1u, selected_identities.size());
    scoped_refptr<X509Certificate> selected_cert =
        selected_identities[0]->certificate();
    EXPECT_TRUE(x509_util::CryptoBufferEqual(client_1->cert_buffer(),
                                             selected_cert->cert_buffer()));
    ASSERT_EQ(1u, selected_cert->intermediate_buffers().size());
    EXPECT_TRUE(x509_util::CryptoBufferEqual(
        client_1_ca->cert_buffer(),
        selected_cert->intermediate_buffers()[0].get()));

    scoped_refptr<SSLPrivateKey> ssl_private_key;
    base::RunLoop key_loop;
    selected_identities[0]->AcquirePrivateKey(
        base::BindOnce(SavePrivateKeyAndQuitCallback, &ssl_private_key,
                       key_loop.QuitClosure()));
    key_loop.Run();
    ASSERT_TRUE(ssl_private_key);
    EXPECT_EQ(expected, ssl_private_key->GetAlgorithmPreferences());
    TestSSLPrivateKeyMatches(ssl_private_key.get(), pkcs8_key);
  }
}