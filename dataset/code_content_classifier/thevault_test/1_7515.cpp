DEF_TEST(wangs_formula_conic_matches_reference, r) {
    SkRandom rand;
    for (int i = -10; i <= 10; ++i) {
        const float w = std::ldexp(1 + rand.nextF(), i);
        for_random_beziers(3, &rand, [&r, w](const SkPoint pts[]) {
            const float ref_nsegs = wangs_formula_conic_reference_impl(kPrecision, pts, w);
            const float nsegs = wangs_formula::conic(kPrecision, pts, w);

            // Because the Gr version may implement the math differently for performance,
            // allow different slack in the comparison based on the rough scale of the answer.
            const float cmpThresh = ref_nsegs * (1.f / (1 << 20));
            REPORTER_ASSERT(r, SkScalarNearlyEqual(ref_nsegs, nsegs, cmpThresh));
        });
    }
}