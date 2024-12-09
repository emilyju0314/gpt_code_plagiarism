Float GlitteringConductorReflection::D_P(const Vector3f &wm, Point2f st,
                                         Vector2f dst0, Vector2f dst1) const {
    Vector2f slopeH(-wm.x / wm.z, -wm.y / wm.z);

    // Without footprint, we evaluate the SDF at the last LOD
    Float minorLength = std::min(dst0.Length(), dst1.Length());
    if (minorLength == 0.) {
        return SDFLastLOD(slopeH) / (wm.z * wm.z * wm.z * wm.z);
    } else {
        // LOD of the MIP hierarchy
        Float l = N_LEVELS_VIRTUAL_MIPMAP - 1. + std::log2(minorLength);
        // Negative LODs are not allowed. Set N_LEVELS_VIRTUAL_MIPMAP to greater
        // value to avoid this case
        CHECK_GE(l, 0.);

        // Discrete MIP LOD
        int il = int(std::floor(l));

        // Weight of the two adjacent LODs
        Float w = l - il;

        // Number of cells on the side at current level
        uint64_t nCellsOnTheSide =
            std::pow(2, (N_LEVELS_VIRTUAL_MIPMAP - 1 - il));
        double cellArea = 1. / (nCellsOnTheSide * nCellsOnTheSide);
        // Number of microfacets in the current LOD
        double n_il = cellArea * std::exp(logMicrofacetDensity);

        // Corresponding continuous distribution LOD
        Float LOD_dist_il = std::log(n_il) / 1.38629;  // 2. * log(2) = 1.38629

        // The model is not defined for negative distribution LOD
        // At this scale, we begin to see each cell individually and each
        // distribution of 4 lobes within these cells.
        if (LOD_dist_il < 0.) {
            // We will increase the LOD of the distribution by
            // std::abs(std::floor(LOD_dist_il)), so we need to increase the LOD
            // of the MIP hierarchy by std::abs(std::floor(LOD_dist_il)) in
            // order to keep consistency between the two hierarchies
            int floor_LOD_dist_il = std::abs(std::floor(LOD_dist_il));
            il += floor_LOD_dist_il;
            w = 0.;

            LOD_dist_il = 0.;
        }

        // Corresponding continuous distribution LOD + 1
        Float LOD_dist_ilp1 = LOD_dist_il + 1.;

        // Default value at distribution LOD >= nLevels
        Float P22_P_il = SDFLastLOD(slopeH);
        Float P22_P_ilp1 = P22_P_il;

        // When the distribution level is greater than nLevels, we don't need to
        // go through the pixel footprint's cells.
        if (LOD_dist_il < nLevels && w != 1.)
            P22_P_il =
                P22_P_discreteLOD(il, slopeH, st, dst0, dst1, LOD_dist_il);
        if (LOD_dist_ilp1 < nLevels && w != 0.)
            P22_P_ilp1 = P22_P_discreteLOD(il + 1, slopeH, st, dst0, dst1,
                                           LOD_dist_ilp1);

        // The value of the P-SDF
        Float P22_P = Lerp(w, P22_P_il, P22_P_ilp1);

        // The value of the P-NDF (slope to normal transformation)
        return P22_P / (wm.z * wm.z * wm.z * wm.z);
    }
}