float pq_L2sqr(const uint8_t *code, const float * precomputed_table, size_t code_size, size_t ksub)
    {
        float result = 0.;
        const size_t dim = code_size >> 2;
        size_t m = 0;
        for (size_t i = 0; i < dim; i++) {
            result += precomputed_table[ksub * m + code[m]]; m++;
            result += precomputed_table[ksub * m + code[m]]; m++;
            result += precomputed_table[ksub * m + code[m]]; m++;
            result += precomputed_table[ksub * m + code[m]]; m++;
        }
        return result;
    }