static float wangs_formula_conic_reference_impl(float precision,
                                                const SkPoint P[3],
                                                const float w) {
    // Compute center of bounding box in projected space
    float min_x = P[0].fX, max_x = min_x,
          min_y = P[0].fY, max_y = min_y;
    for (int i = 1; i < 3; i++) {
        min_x = std::min(min_x, P[i].fX);
        max_x = std::max(max_x, P[i].fX);
        min_y = std::min(min_y, P[i].fY);
        max_y = std::max(max_y, P[i].fY);
    }
    const SkPoint C = SkPoint::Make(0.5f * (min_x + max_x), 0.5f * (min_y + max_y));

    // Translate control points and compute max length
    SkPoint tP[3] = {P[0] - C, P[1] - C, P[2] - C};
    float max_len = 0;
    for (int i = 0; i < 3; i++) {
        max_len = std::max(max_len, tP[i].length());
    }
    SkASSERT(max_len > 0);

    // Compute delta = parametric step size of linearization
    const float eps = 1 / precision;
    const float r_minus_eps = std::max(0.f, max_len - eps);
    const float min_w = std::min(w, 1.f);
    const float numer = 4 * min_w * eps;
    const float denom =
            (tP[2] - tP[1] * 2 * w + tP[0]).length() + r_minus_eps * std::abs(1 - 2 * w + 1);
    const float delta = sqrtf(numer / denom);

    // Return corresponding num segments in the interval [tmin,tmax]
    constexpr float tmin = 0, tmax = 1;
    SkASSERT(delta > 0);
    return (tmax - tmin) / delta;
}