void hashtest(uint32_t version, uint32_t t, uint32_t m, uint32_t p, const char *pwd,
              const char *salt, const char *hexref, const char *mcfref, argon2_type type) {
    unsigned char out[OUT_LEN];
    unsigned char hex_out[OUT_LEN * 2 + 4];
    char encoded[ENCODED_LEN];
    int ret, i;

    printf("Hash test: $v=%d t=%d, m=%d, p=%d, pass=%s, salt=%s: ", version,
           t, m, p, pwd, salt);

    ret = argon2_hash(t, 1 << m, p, pwd, strlen(pwd), salt, strlen(salt), out,
                      OUT_LEN, encoded, ENCODED_LEN, type, version);
    REQUIRE(ret == ARGON2_OK);

    for(i = 0; i < OUT_LEN; ++i)
        sprintf((char *)(hex_out + i * 2), "%02x", out[i]);
    REQUIRE(memcmp(hex_out, hexref, OUT_LEN * 2) == 0);

    if(ARGON2_VERSION_NUMBER == version) {
        REQUIRE(memcmp(encoded, mcfref, strlen(mcfref)) == 0);
    }

    ret = argon2_verify(encoded, pwd, strlen(pwd), type);
    REQUIRE(ret == ARGON2_OK);
    ret = argon2_verify(mcfref, pwd, strlen(pwd), type);
    REQUIRE(ret == ARGON2_OK);

    printf("PASS\n");
}