TEST_F(rnp_tests, test_load_keyring_and_count_pgp)
{
    unsigned int primary_count = 2;
    unsigned int subkey_counts[2] = {3, 2};

    // check pubring
    check_pgp_keyring_counts("data/keyrings/1/pubring.gpg", primary_count, subkey_counts);

    // check secring
    check_pgp_keyring_counts("data/keyrings/1/secring.gpg", primary_count, subkey_counts);
}