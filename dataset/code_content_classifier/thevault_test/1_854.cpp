inline bool compare_L2_err(const float* reference, const float* data,
    const unsigned int len, const float epsilon)
{
    HPX_ASSERT(epsilon >= 0);

    float error = 0;
    float ref = 0;

    hpx::for_loop(hpx::execution::par, 0, len, [&](int i) {
        float diff = reference[i] - data[i];
        error += diff * diff;
        ref += reference[i] * reference[i];
    });

    float normRef = sqrtf(ref);
    if (std::fabs(ref) < 1e-7f)
    {
        return false;
    }

    float normError = sqrtf(error);
    error = normError / normRef;
    bool result = error < epsilon;
    return result;
}