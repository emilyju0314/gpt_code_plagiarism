TEST_F(rnp_tests, test_load_check_bitfields_and_times_v3)
{
    uint8_t                keyid[PGP_KEY_ID_SIZE];
    uint8_t                signer_id[PGP_KEY_ID_SIZE];
    const pgp_key_t *      key;
    const pgp_signature_t *sig = NULL;

    // load keyring
    rnp_key_store_t *key_store =
      rnp_key_store_new(PGP_KEY_STORE_GPG, "data/keyrings/2/pubring.gpg");
    assert_non_null(key_store);
    assert_true(rnp_key_store_load_from_path(key_store, NULL));

    // find
    key = NULL;
    assert_true(rnp_hex_decode("DC70C124A50283F1", keyid, sizeof(keyid)));
    key = rnp_key_store_get_key_by_id(key_store, keyid, NULL);
    assert_non_null(key);
    // check key version
    assert_int_equal(pgp_key_get_version(key), PGP_V3);
    // check subsig count
    assert_int_equal(pgp_key_get_subsig_count(key), 1);
    sig = &pgp_key_get_subsig(key, 0)->sig;
    // check signature version
    assert_int_equal(sig->version, 3);
    // check issuer
    assert_true(rnp_hex_decode("DC70C124A50283F1", keyid, sizeof(keyid)));
    assert_true(signature_get_keyid(sig, signer_id));
    assert_int_equal(memcmp(keyid, signer_id, PGP_KEY_ID_SIZE), 0);
    // check creation time
    assert_int_equal(signature_get_creation(sig), 1005209227);
    assert_int_equal(signature_get_creation(sig), pgp_key_get_creation(key));
    // check signature expiration time (V3 sigs have none)
    assert_int_equal(signature_get_expiration(sig), 0);
    // check key expiration
    assert_int_equal(pgp_key_get_expiration(key), 0); // only for V4 keys
    assert_int_equal(pgp_key_get_pkt(key)->v3_days, 0);

    // cleanup
    rnp_key_store_free(key_store);
}