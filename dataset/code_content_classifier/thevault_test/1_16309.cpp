bool SignatureManager::VerifyCaChain() {
  if (!certificate_)
    return false;

  X509_STORE_CTX *csc = NULL;
  csc = X509_STORE_CTX_new();
  assert(csc);

  X509_STORE_CTX_init(csc, x509_store_, certificate_, NULL);
  bool result = X509_verify_cert(csc) == 1;
  X509_STORE_CTX_free(csc);

  return result;
}