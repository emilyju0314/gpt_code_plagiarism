real_vector rand_real_vector(
    size_t   rank,
    real_t   norm  = 1.0,
    bool     no_0s = false,
    unsigned scale = MATH_DEFAULT_RAND_SCALE)
{
    assert(norm >= 0.0);

    real_vector x(rank);

    real_t x_norm2(0);

    for (size_t i = 0; i < rank; ++i) {
        real_t x_i;
        do x_i = rand_real(-1.0, 1.0, scale);
        while (no_0s && 0.0 == x_i);

        x_norm2 += x_i * x_i;

        x[i] = x_i;
    }

    real_t f = sqrt(norm * norm / x_norm2);
    for (size_t i = 0; i < rank; ++i) {
        x[i] *= f;
    }

    return x;
}