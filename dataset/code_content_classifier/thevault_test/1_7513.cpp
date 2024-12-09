DEF_TEST(wangs_formula_rational_quad_reduces, r) {
    constexpr static float kTessellationTolerance = 1 / 128.f;

    SkRandom rand;
    for (int i = 0; i < 100; ++i) {
        for_random_beziers(3, &rand, [&r](const SkPoint pts[]) {
            const float rational_nsegs = wangs_formula::conic(kPrecision, pts, 1.f);
            const float integral_nsegs = wangs_formula_quadratic_reference_impl(kPrecision, pts);
            REPORTER_ASSERT(
                    r, SkScalarNearlyEqual(rational_nsegs, integral_nsegs, kTessellationTolerance));
        });
    }
}