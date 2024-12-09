Float GlitteringConductorReflection::P22_P_discreteLOD(
    int l, const Vector2f &slope_h, Point2f st, Vector2f dst0, Vector2f dst1,
    Float lDist) const {
    int pyrSize = std::pow(2, N_LEVELS_VIRTUAL_MIPMAP - 1 - l);

    st[0] = st[0] * pyrSize - 0.5f;
    st[1] = st[1] * pyrSize - 0.5f;

    dst0[0] *= pyrSize;
    dst0[1] *= pyrSize;
    dst1[0] *= pyrSize;
    dst1[1] *= pyrSize;

    // Compute ellipse coefficients to bound filter region
    Float A = dst0[1] * dst0[1] + dst1[1] * dst1[1] + 1;
    Float B = -2 * (dst0[0] * dst0[1] + dst1[0] * dst1[1]);
    Float C = dst0[0] * dst0[0] + dst1[0] * dst1[0] + 1;
    Float invF = 1 / (A * C - B * B * 0.25f);
    A *= invF;
    B *= invF;
    C *= invF;

    // Compute the ellipse's bounding box in texture space
    Float det = -B * B + 4 * A * C;
    Float invDet = 1 / det;
    Float uSqrt = std::sqrt(det * C), vSqrt = std::sqrt(A * det);
    int s0 = std::ceil(st[0] - 2 * invDet * uSqrt);
    int s1 = std::floor(st[0] + 2 * invDet * uSqrt);
    int t0 = std::ceil(st[1] - 2 * invDet * vSqrt);
    int t1 = std::floor(st[1] + 2 * invDet * vSqrt);

    // Scan over ellipse bound and compute quadratic equation
    Float sum(0.f);
    Float sumWts = 0;
    for (int it = t0; it <= t1; ++it) {
        Float tt = it - st[1];
        int itIndex = it - t0;
        for (int is = s0; is <= s1; ++is) {
            Float ss = is - st[0];
            int isIndex = is - s0;
            // Compute squared radius and evaluate the SDF if inside ellipse
            Float r2 = A * ss * ss + B * ss * tt + C * tt * tt;
            if (r2 < 1) {
                Float alpha = 2;
                // Weighting function used in pbrt-v3 EWA function
                Float W_P = std::exp(-alpha * r2) - std::exp(-alpha);

                sum += P22_M(l, is, it, slope_h, lDist) * W_P;
                sumWts += W_P;
            }
        }
    }
    return sum / sumWts;
}