DEF_TEST(wangs_formula_conic_within_tol, r) {
    constexpr int maxExponent = 24;

    // Single-precision functions in SkConic/SkGeometry lose too much accuracy with
    // large-magnitude curves and large weights for this test to pass.
    using Sk2d = skvx::Vec<2, double>;
    const auto eval_conic = [](const SkPoint pts[3], float w, float t) -> Sk2d {
        const auto eval = [](Sk2d A, Sk2d B, Sk2d C, float t) -> Sk2d {
            return (A * t + B) * t + C;
        };

        const Sk2d p0 = {pts[0].fX, pts[0].fY};
        const Sk2d p1 = {pts[1].fX, pts[1].fY};
        const Sk2d p1w = p1 * w;
        const Sk2d p2 = {pts[2].fX, pts[2].fY};
        Sk2d numer = eval(p2 - p1w * 2 + p0, (p1w - p0) * 2, p0, t);

        Sk2d denomC = {1, 1};
        Sk2d denomB = {2 * (w - 1), 2 * (w - 1)};
        Sk2d denomA = {-2 * (w - 1), -2 * (w - 1)};
        Sk2d denom = eval(denomA, denomB, denomC, t);
        return numer / denom;
    };

    const auto dot = [](const Sk2d& a, const Sk2d& b) -> double {
        return a[0] * b[0] + a[1] * b[1];
    };

    const auto length = [](const Sk2d& p) -> double { return sqrt(p[0] * p[0] + p[1] * p[1]); };

    SkRandom rand;
    for (int i = -10; i <= 10; ++i) {
        const float w = std::ldexp(1 + rand.nextF(), i);
        for_random_beziers(
                3, &rand,
                [&](const SkPoint pts[]) {
                    const int nsegs = SkScalarCeilToInt(wangs_formula::conic(kPrecision, pts, w));

                    const float tdelta = 1.f / nsegs;
                    for (int j = 0; j < nsegs; ++j) {
                        const float tmin = j * tdelta, tmax = (j + 1) * tdelta,
                                    tmid = 0.5f * (tmin + tmax);

                        Sk2d p0, p1, p2;
                        p0 = eval_conic(pts, w, tmin);
                        p1 = eval_conic(pts, w, tmid);
                        p2 = eval_conic(pts, w, tmax);

                        // Get distance of p1 to baseline (p0, p2).
                        const Sk2d n = {p2[1] - p0[1], p0[0] - p2[0]};
                        SkASSERT(length(n) != 0);
                        const double d = std::abs(dot(p1 - p0, n)) / length(n);

                        // Check distance is within tolerance
                        REPORTER_ASSERT(r, d <= (1.0 / kPrecision) + SK_ScalarNearlyZero);
                    }
                },
                maxExponent);
    }
}