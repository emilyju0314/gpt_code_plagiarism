bool Verify(const unsigned char *buffer, const unsigned buffer_size,
            const unsigned char *signature, const unsigned signature_size)
{
  if (!certificate_) return false;

  bool result = false;
  EVP_MD_CTX ctx;

  EVP_MD_CTX_init(&ctx);
  if (EVP_VerifyInit(&ctx, EVP_sha1()) &&
      EVP_VerifyUpdate(&ctx, buffer, buffer_size) &&
      EVP_VerifyFinal(&ctx, signature, signature_size,
                      X509_get_pubkey(certificate_)))
  {
    result = true;
  }
  EVP_MD_CTX_cleanup(&ctx);

  return result;
}