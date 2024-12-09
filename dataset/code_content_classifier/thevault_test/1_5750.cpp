TEST_F(rnp_tests, test_load_v4_keyring_pgp)
{
    pgp_source_t src = {};

    rnp_key_store_t *key_store = (rnp_key_store_t *) calloc(1, sizeof(*key_store));
    assert_non_null(key_store);

    // load it in to the key store
    assert_rnp_success(init_file_src(&src, "data/keyrings/1/pubring.gpg"));
    assert_rnp_success(rnp_key_store_pgp_read_from_src(key_store, &src));
    src_close(&src);
    assert_int_equal(7, rnp_key_store_get_key_count(key_store));

    // find the key by keyid
    static const uint8_t keyid[] = {0x8a, 0x05, 0xb8, 0x9f, 0xad, 0x5a, 0xde, 0xd1};
    const pgp_key_t *    key = rnp_key_store_get_key_by_id(key_store, keyid, NULL);
    assert_non_null(key);

    // confirm the key flags are correct
    assert_int_equal(pgp_key_get_flags(key), PGP_KF_ENCRYPT);

    // cleanup
    rnp_key_store_free(key_store);
}