static void
check_pgp_keyring_counts(const char *   path,
                         unsigned       primary_count,
                         const unsigned subkey_counts[])
{
    pgp_source_t     src = {};
    rnp_key_store_t *key_store = (rnp_key_store_t *) calloc(1, sizeof(*key_store));

    assert_non_null(key_store);
    // load it in to the key store
    assert_rnp_success(init_file_src(&src, path));
    assert_rnp_success(rnp_key_store_pgp_read_from_src(key_store, &src));
    src_close(&src);

    // count primary keys first
    unsigned total_primary_count = 0;
    for (size_t i = 0; i < rnp_key_store_get_key_count(key_store); i++) {
        if (pgp_key_is_primary_key(rnp_key_store_get_key(key_store, i))) {
            total_primary_count++;
        }
    }
    assert_int_equal(primary_count, total_primary_count);

    // now count subkeys in each primary key
    unsigned total_subkey_count = 0;
    unsigned primary = 0;
    for (size_t i = 0; i < rnp_key_store_get_key_count(key_store); i++) {
        pgp_key_t *key = rnp_key_store_get_key(key_store, i);
        if (pgp_key_is_primary_key(key)) {
            // check the subkey count for this primary key
            assert_int_equal(pgp_key_get_subkey_count(key), subkey_counts[primary++]);
        } else if (pgp_key_is_subkey(key)) {
            total_subkey_count++;
        }
    }

    // check the total (not really needed)
    assert_int_equal(rnp_key_store_get_key_count(key_store),
                     total_primary_count + total_subkey_count);

    // cleanup
    rnp_key_store_free(key_store);
}