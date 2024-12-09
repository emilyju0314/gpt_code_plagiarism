Float GlitteringConductorReflection::Sample_P(const Point2f &u, int i,
                                              int l) const {
    // The distribution equals 0 after 4 standard deviations.
    // Slope standard deviation = alpha / sqrt(2)
    // 0.707106 \approx 1 / sqrt(2)
    Float alpha_dist_isqrt2_4 = alphaDict * 0.707106 * 4.;

    // Samples the positive part of the 1D distribution
    // Sampled value is in [0, 1)
    Float sample = (*distributions)[l * N + i].SampleContinuous(u.x, nullptr);
    // The 1D distribution is an even function
    // [-1, 1]
    if (u.y < 0.5) sample *= -1.;

    // [-alpha_dist_isqrt2_4, alpha_dist_isqrt2_4]
    return sample * alpha_dist_isqrt2_4;
}