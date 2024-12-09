bool SignatureManager::Sign(const unsigned char *buffer,
                            const unsigned buffer_size,
                            unsigned char **signature,
                            unsigned *signature_size)
{
  if (!private_key_) {
    *signature_size = 0;
    *signature = NULL;
    return false;
  }

  bool result = false;
  EVP_MD_CTX ctx;

  *signature = reinterpret_cast<unsigned char *>(
                 smalloc(EVP_PKEY_size(private_key_)));
  EVP_MD_CTX_init(&ctx);
  if (EVP_SignInit(&ctx, EVP_sha1()) &&
      EVP_SignUpdate(&ctx, buffer, buffer_size) &&
      EVP_SignFinal(&ctx, *signature, signature_size, private_key_))
  {
    result = true;
  }
  EVP_MD_CTX_cleanup(&ctx);
  if (!result) {
    free(*signature);
    *signature_size = 0;
    *signature = NULL;
  }

  return result;
}