DEF_TEST(wangs_formula_conic_vectorXforms, r) {
    auto check_conic_with_transform = [&](const SkPoint* pts, float w, const SkMatrix& m) {
        SkPoint ptsXformed[3];
        m.mapPoints(ptsXformed, pts, 3);
        float expected = wangs_formula::conic(kPrecision, ptsXformed, w);
        float actual = wangs_formula::conic(kPrecision, pts, w, wangs_formula::VectorXform(m));
        REPORTER_ASSERT(r, SkScalarNearlyEqual(actual, expected));
    };

    SkRandom rand;
    for (int i = -10; i <= 10; ++i) {
        const float w = std::ldexp(1 + rand.nextF(), i);
        for_random_beziers(3, &rand, [&](const SkPoint pts[]) {
            check_conic_with_transform(pts, w, SkMatrix::I());
            check_conic_with_transform(
                    pts, w, SkMatrix::Scale(rand.nextRangeF(-10, 10), rand.nextRangeF(-10, 10)));

            // Random 2x2 matrix
            SkMatrix m;
            m.setScaleX(rand.nextRangeF(-10, 10));
            m.setSkewX(rand.nextRangeF(-10, 10));
            m.setSkewY(rand.nextRangeF(-10, 10));
            m.setScaleY(rand.nextRangeF(-10, 10));
            check_conic_with_transform(pts, w, m);
        });
    }
}