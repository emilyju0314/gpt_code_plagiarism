void clamp_seed(uint32_t s[4])
{
    if (s[0] < 1)
        s[0] = 1;
    if (s[0] > S0_MAX)
        s[0] = S0_MAX;

    if (s[1] < 1)
        s[1] = 1;
    if (s[1] > S1_MAX)
        s[1] = S1_MAX;

    if (s[2] < 1)
        s[2] = 1;
    if (s[2] > S2_MAX)
        s[2] = S2_MAX;

    if (s[3] < 1)
        s[3] = 1;
    if (s[3] > S3_MAX)
        s[3] = S3_MAX;
}