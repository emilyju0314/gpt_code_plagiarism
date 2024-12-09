DEF_TEST(wangs_formula_quad_within_tol, r) {
    // Wang's formula and the quad math starts to lose precision with very large
    // coordinate values, so limit the magnitude a bit to prevent test failures
    // due to loss of precision.
    constexpr int maxExponent = 15;
    SkRandom rand;
    for_random_beziers(3, &rand, [&r](const SkPoint pts[]) {
        const int nsegs = static_cast<int>(
                std::ceil(wangs_formula_quadratic_reference_impl(kPrecision, pts)));

        const float tdelta = 1.f / nsegs;
        for (int j = 0; j < nsegs; ++j) {
            const float tmin = j * tdelta, tmax = (j + 1) * tdelta;

            // Get section of quad in [tmin,tmax]
            const SkPoint* sectionPts;
            SkPoint tmp0[5];
            SkPoint tmp1[5];
            if (tmin == 0) {
                if (tmax == 1) {
                    sectionPts = pts;
                } else {
                    SkChopQuadAt(pts, tmp0, tmax);
                    sectionPts = tmp0;
                }
            } else {
                SkChopQuadAt(pts, tmp0, tmin);
                if (tmax == 1) {
                    sectionPts = tmp0 + 2;
                } else {
                    SkChopQuadAt(tmp0 + 2, tmp1, (tmax - tmin) / (1 - tmin));
                    sectionPts = tmp1;
                }
            }

            // For quads, max distance from baseline is always at t=0.5.
            SkPoint p;
            p = SkEvalQuadAt(sectionPts, 0.5f);

            // Get distance of p to baseline
            const SkPoint n = {sectionPts[2].fY - sectionPts[0].fY,
                               sectionPts[0].fX - sectionPts[2].fX};
            const float d = std::abs((p - sectionPts[0]).dot(n)) / n.length();

            // Check distance is within specified tolerance
            REPORTER_ASSERT(r, d <= (1.f / kPrecision) + SK_ScalarNearlyZero);
        }
    }, maxExponent);
}