bool SignatureManager::VerifyPkcs7(const unsigned char *buffer,
                                   const unsigned buffer_size,
                                   unsigned char **content,
                                   unsigned *content_size,
                                   vector<string> *alt_uris)
{
  *content = NULL;
  *content_size = 0;

  BIO *bp_pkcs7 = BIO_new(BIO_s_mem());
  if (!bp_pkcs7) return false;
  if (BIO_write(bp_pkcs7, buffer, buffer_size) <= 0) {
    BIO_free(bp_pkcs7);
    return false;
  }

  PKCS7 *pkcs7 = NULL;
  pkcs7 = PEM_read_bio_PKCS7(bp_pkcs7, NULL, NULL, NULL);
  BIO_free(bp_pkcs7);
  if (!pkcs7) {
    LogCvmfs(kLogSignature, kLogDebug, "invalid pkcs#7 signature");
    return false;
  }

  BIO *bp_content = BIO_new(BIO_s_mem());
  if (!bp_content) {
    PKCS7_free(pkcs7);
    return false;
  }

  int flags = 0;
  STACK_OF(X509) *extra_signers = NULL;
  BIO *indata = NULL;
  bool result = PKCS7_verify(pkcs7, extra_signers, x509_store_, indata,
                             bp_content, flags);
  if (result != 1) {
    BIO_free(bp_content);
    PKCS7_free(pkcs7);
    return false;
  }

  BUF_MEM *bufmem_content;
  BIO_get_mem_ptr(bp_content, &bufmem_content);
  // BIO_free() leaves BUF_MEM alone
  (void) BIO_set_close(bp_content, BIO_NOCLOSE);
  BIO_free(bp_content);
  *content = reinterpret_cast<unsigned char *>(bufmem_content->data);
  *content_size = bufmem_content->length;
  free(bufmem_content);
  if (*content == NULL) {
    PKCS7_free(pkcs7);
    LogCvmfs(kLogSignature, kLogDebug, "empty pkcs#7 structure");
    return false;
  }

  // Extract signing certificates
  STACK_OF(X509) *signers = NULL;
  signers = PKCS7_get0_signers(pkcs7, NULL, 0);
  assert(signers);

  // Extract alternative names
  for (int i = 0; i < sk_X509_num(signers); ++i) {
    X509* this_signer = sk_X509_value(signers, i);
    GENERAL_NAMES *subject_alt_names = NULL;
    subject_alt_names = reinterpret_cast<GENERAL_NAMES *>(
      X509_get_ext_d2i(this_signer, NID_subject_alt_name, NULL, NULL));
    if (subject_alt_names != NULL) {
      for (int j = 0; j < sk_GENERAL_NAME_num(subject_alt_names); ++j) {
        GENERAL_NAME *this_name = sk_GENERAL_NAME_value(subject_alt_names, j);
        if (this_name->type != GEN_URI)
          continue;

        char *name_ptr = reinterpret_cast<char *>(
          ASN1_STRING_data(this_name->d.uniformResourceIdentifier));
        int name_len =
          ASN1_STRING_length(this_name->d.uniformResourceIdentifier);
        if (!name_ptr || (name_len <= 0))
          continue;
        alt_uris->push_back(string(name_ptr, name_len));
      }
    }
  }
  sk_X509_free(signers);
  PKCS7_free(pkcs7);
  return true;
}