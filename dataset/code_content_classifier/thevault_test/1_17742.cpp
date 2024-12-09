bool derive_key(const sample_ec256_dh_shared_t *p_shared_key,
                uint8_t key_id,
                sgx_aes_gcm_128bit_key_t *first_derived_key,
                sgx_aes_gcm_128bit_key_t *second_derived_key) {

  lc_status_t ret = LC_SUCCESS;
  hash_buffer_t hash_buffer;
  lc_sha_state_handle_t sha_context;
  lc_sha256_hash_t key_material;
    
  memset(&hash_buffer, 0, sizeof(hash_buffer_t));

  /* counter in big endian  */
  hash_buffer.counter[3] = key_id;

  /*convert from little endian to big endian */
  for (size_t i = 0; i < sizeof(sgx_ec_dh_shared_t) ; i++) {
    hash_buffer.shared_secret.s[i] = p_shared_key->s[sizeof(p_shared_key->s) - 1 - i];
  }

  ret = lc_sha256_init(&sha_context);
  if (ret != LC_SUCCESS) {
    return false;
  }
  ret = lc_sha256_update((uint8_t*)&hash_buffer, sizeof(hash_buffer_t), sha_context);
  if (ret != LC_SUCCESS) {
    lc_sha256_close(sha_context);
    return false;
  }
  ret = lc_sha256_update((uint8_t*)ID_U, sizeof(ID_U), sha_context);
  if (ret != LC_SUCCESS) {
    lc_sha256_close(sha_context);
    return false;
  }
  ret = lc_sha256_update((uint8_t*)ID_V, sizeof(ID_V), sha_context);
  if (ret != LC_SUCCESS) {
    lc_sha256_close(sha_context);
    return false;
  }
  ret = lc_sha256_get_hash(sha_context, &key_material);
  if (ret != LC_SUCCESS) {
    lc_sha256_close(sha_context);
    return false;
  }
  ret = lc_sha256_close(sha_context);

  static_assert(sizeof(sgx_aes_gcm_128bit_key_t)* 2 == sizeof(sgx_sha256_hash_t), "structure size mismatch.");
  memcpy(first_derived_key, &key_material, sizeof(sgx_aes_gcm_128bit_key_t));
  memcpy(second_derived_key, (uint8_t*)&key_material + sizeof(sgx_aes_gcm_128bit_key_t), sizeof(sgx_aes_gcm_128bit_key_t));

  // memset here can be optimized away by compiler, so please use memset_s on
  // windows for production code and similar functions on other OSes.
  memset(&key_material, 0, sizeof(sgx_aes_gcm_128bit_key_t));

  return true;
}