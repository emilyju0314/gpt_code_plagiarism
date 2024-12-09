TEST_F(rnp_tests, test_load_v3_keyring_pgp)
{
    pgp_source_t src = {};

    rnp_key_store_t *key_store = (rnp_key_store_t *) calloc(1, sizeof(*key_store));
    assert_non_null(key_store);

    // load pubring in to the key store
    assert_rnp_success(init_file_src(&src, "data/keyrings/2/pubring.gpg"));
    assert_rnp_success(rnp_key_store_pgp_read_from_src(key_store, &src));
    src_close(&src);
    assert_int_equal(1, rnp_key_store_get_key_count(key_store));

    // find the key by keyid
    static const uint8_t keyid[] = {0xDC, 0x70, 0xC1, 0x24, 0xA5, 0x02, 0x83, 0xF1};
    const pgp_key_t *    key = rnp_key_store_get_key_by_id(key_store, keyid, NULL);
    assert_non_null(key);

    // confirm the key flags are correct
    assert_int_equal(pgp_key_get_flags(key),
                     PGP_KF_ENCRYPT | PGP_KF_SIGN | PGP_KF_CERTIFY | PGP_KF_AUTH);

    // confirm that key expiration is correct
    assert_int_equal(pgp_key_get_expiration(key), 0);

    // cleanup
    rnp_key_store_free(key_store);

    // load secret keyring and decrypt the key

    key_store = (rnp_key_store_t *) calloc(1, sizeof(*key_store));
    assert_non_null(key_store);

    assert_rnp_success(init_file_src(&src, "data/keyrings/4/secring.pgp"));
    assert_rnp_success(rnp_key_store_pgp_read_from_src(key_store, &src));
    src_close(&src);
    assert_int_equal(1, rnp_key_store_get_key_count(key_store));

    static const uint8_t keyid2[] = {0x7D, 0x0B, 0xC1, 0x0E, 0x93, 0x34, 0x04, 0xC9};
    key = rnp_key_store_get_key_by_id(key_store, keyid2, NULL);
    assert_non_null(key);

    // confirm the key flags are correct
    assert_int_equal(pgp_key_get_flags(key),
                     PGP_KF_ENCRYPT | PGP_KF_SIGN | PGP_KF_CERTIFY | PGP_KF_AUTH);

    // check if the key is secret and is locked
    assert_true(pgp_key_is_secret(key));
    assert_true(pgp_key_is_locked(key));

    // decrypt the key
    const pgp_rawpacket_t *pkt = pgp_key_get_rawpacket(key, 0);
    pgp_key_pkt_t *        seckey =
      pgp_decrypt_seckey_pgp(pkt->raw, pkt->length, pgp_key_get_pkt(key), "password");
    assert_non_null(seckey);

    // cleanup
    free_key_pkt(seckey);
    free(seckey);
    rnp_key_store_free(key_store);
}