TEST(prefix_lcs, prefix_lcs_vs_skewed_prefix) {

    for (int b_size = MIN_SIZE_B; b_size < MAX_SIZE_B; b_size += STEP) {
        for (int a_size = 1; a_size <= b_size; a_size += STEP) {
            for (int i = 0; i < ITERATIONS_PER_INPUT; ++i) {
                for (int alphabet = 1; alphabet < 25; ++alphabet) {
                    auto seq_a = gen_vector_seq<int>(a_size, alphabet);
                    auto seq_b = gen_vector_seq<int>(b_size, alphabet);
                    auto a = new int[a_size];
                    auto b = new int[b_size];
                    for (int j = 0; j < a_size; ++j) a[j] = seq_a[j];
                    for (int j = 0; j < b_size; ++j) b[j] = seq_b[j];


                    auto expected = prefix_lcs_sequential(a, a_size, b, b_size);
                    auto actual = prefix_lcs_sequential_skewed(a, a_size, b, b_size);

                    delete[] a;
                    delete[] b;

                    EXPECT_EQ(expected, actual);
                }

            }
        }
    }
}