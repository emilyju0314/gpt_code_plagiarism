Vector2f GlitteringConductorReflection::Sample_P22_P_discreteLOD(
    int l, Point2f st, Vector2f dst0, Vector2f dst1, Float lDist) const {
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

    // Width of the bounding box of the ray footprint
    int resX = s1 - s0;
    // Just in case
    CHECK_GT(resX, 0);
    // Height of the bounding box of the ray footprint
    int resY = t1 - t0;
    // Just in case
    CHECK_GT(resY, 0);

    // Will contain the weights associated to the cells within the ray
    // footprint
    std::vector<Float> WPValues((resX + 1) * (resY + 1));

    // Scan over ellipse bound and compute quadratic equation
    Float sum(0.f);
    Float sumWts = 0;
    for (int it = t0; it <= t1; ++it) {
        Float tt = it - st[1];
        int itIndex = it - t0;
        for (int is = s0; is <= s1; ++is) {
            Float ss = is - st[0];
            int isIndex = is - s0;
            // Compute squared radius and compute the weight if inside ellipse
            Float r2 = A * ss * ss + B * ss * tt + C * tt * tt;
            if (r2 < 1) {
                Float alpha = 2;
                // Weighting function used in pbrt-v3 EWA function
                Float W_P = std::exp(-alpha * r2) - std::exp(-alpha);

                WPValues[itIndex * (resX + 1) + isIndex] = W_P;

                sumWts += W_P;
            } else {
                WPValues[itIndex * (resX + 1) + isIndex] = 0.;
            }
        }
    }
    // Normalizes the weights
    for (int i = 0; i < WPValues.size(); ++i) WPValues[i] /= sumWts;
    // Create a piecewise constant 2D distribution with the weights of the cells
    // within the ray footprint
    Distribution2D WPLOD(WPValues.data(), resX + 1, resY + 1);

    // Sample a cell within the ray footprint
    Point2f u(rngSample->UniformFloat(), rngSample->UniformFloat());
    Point2i sampledCell = WPLOD.SampleDiscrete(u);
    sampledCell += Vector2i(s0, t0);

    // Samples the transformed SDF within the sampled cell
    return Sample_P22_M(l, sampledCell.x, sampledCell.y, lDist);
}