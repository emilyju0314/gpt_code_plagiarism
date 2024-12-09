bool EncryptDataWithCredential(bool encrypt_flag, TPM_ALG_ID hash_alg_id,
                 TPM2B_DIGEST unmarshaled_credential,
                 TPM2B_DIGEST marshaled_credential,
                 int size_input_data, byte* input_data,
                 int* size_hmac, byte* encrypted_data_hmac,
                 int* size_output_data, byte* output_data) {
  int size_derived_keys = 128;
  byte derived_keys[128];
  byte decrypt_mac[128];
  string data_encryption_key_seed;
  string label;
  string contextV;
  byte* encrypted_data = output_data;

  *size_hmac = SizeHash(hash_alg_id);
  data_encryption_key_seed.assign((const char*)unmarshaled_credential.buffer,
                       unmarshaled_credential.size);
  label = "PROTECT";
  if (!KDFa(hash_alg_id, data_encryption_key_seed, label, contextV, contextV, 256,
            size_derived_keys, derived_keys)) {
    printf("Can't derive protection keys\n");
    return false;
  }

  memset(output_data, 0, *size_output_data);
  if (!AesCtrCrypt(128, derived_keys, size_input_data, input_data, output_data)) {
    printf("Can't encrypt input\n");
    return false;
  }
  *size_output_data = size_input_data;
  if (!encrypt_flag)
    encrypted_data = input_data;
  else
    encrypted_data = output_data;
  HMAC_CTX hctx;
  HMAC_CTX_init(&hctx);
  if (hash_alg_id == TPM_ALG_SHA1) {
    HMAC_Init_ex(&hctx, &derived_keys[16], 16, EVP_sha1(), nullptr);
    *size_hmac = 20;
  } else {
    HMAC_Init_ex(&hctx, &derived_keys[16], 16, EVP_sha256(), nullptr);
    *size_hmac = 32;
  }
  HMAC_Update(&hctx, encrypted_data, size_input_data);
  if (encrypt_flag) {
    HMAC_Final(&hctx, encrypted_data_hmac, (uint32_t*)size_hmac);
    HMAC_CTX_cleanup(&hctx);
  } else {
    HMAC_Final(&hctx, decrypt_mac, (uint32_t*)size_hmac);
    HMAC_CTX_cleanup(&hctx);
    if (memcmp(decrypt_mac, encrypted_data_hmac, *size_hmac) != 0)
      return false;
  }

  return true;
}