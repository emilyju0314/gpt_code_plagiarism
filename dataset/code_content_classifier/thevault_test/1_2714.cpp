uint32_t *Twofish::set_key(const uint32_t in_key[], const uint32_t key_len) {
    uint32_t i, a, b, me_key[4], mo_key[4];
#ifdef Q_TABLES
    if (!qt_gen) {
        gen_qtab();
        qt_gen = 1;
    }
#endif

#ifdef M_TABLE
    if (!mt_gen) {
        gen_mtab();
        mt_gen = 1;
    }

#endif

    p_k_len = key_len / 64; /* 2, 3 or 4 */
    for (i = 0; i < p_k_len; ++i) {
        a = in_key[i + i];
        me_key[i] = a;
        b = in_key[i + i + 1];
        mo_key[i] = b;
        p_s_key[p_k_len - i - 1] = mds_rem(a, b);
    }

    for (i = 0; i < 40; i += 2) {
        a = 0x01010101 * i;
        b = a + 0x01010101;
        a = h_fun(a, me_key);
        b = rotl(h_fun(b, mo_key), 8);
        p_l_key[i] = a + b;
        p_l_key[i + 1] = rotl(a + 2 * b, 9);
    }

#ifdef MK_TABLE
    gen_mk_tab(p_s_key);
#endif

    return p_l_key;
}