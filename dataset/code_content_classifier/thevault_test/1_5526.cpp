Vector3f GlitteringConductorReflection::Sample_D_P() const {
    Float minorLength = std::min(dstdx.Length(), dstdy.Length());

    // If the intersection has not partial derivatives or if we sample the
    // approximated SDF, we sample the SDF at the last LOD
    if (minorLength == 0. || sampleApproximation) {
        Vector2f sampledSlope = SampleSDFLastLOD();

        return SlopeToNormal(sampledSlope);
    } else {
        // LOD of the MIP hierarchy
        Float l = N_LEVELS_VIRTUAL_MIPMAP - 1. + std::log2(minorLength);
        // Negative LODs are not allowed. Set N_LEVELS_VIRTUAL_MIPMAP to greater
        // value to avoid this case
        CHECK_GE(l, 0.);

        // Discrete MIP LOD
        int il = int(floor(l));

        // Weight of the two adjacent LODs
        float w = l - float(il);

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

        // Sample an adjacent LOD based on w value
        Float uLOD = rngSample->UniformFloat();
        if (uLOD < w) {
            il += 1;
            LOD_dist_il += 1.;
        }

        Vector2f sampledSlope;
        // Samples a cell within the pixel footprint then its associated SDF
        if (LOD_dist_il < nLevels) {
            sampledSlope =
                Sample_P22_P_discreteLOD(il, st, dstdx, dstdy, LOD_dist_il);
        }
        // When the distribution level is greater than nLevels, we don't need to
        // sample the pixel footprint In this case, we sample the SDF of the
        // last LOD
        else {
            sampledSlope = SampleSDFLastLOD();
        }
        return SlopeToNormal(sampledSlope);
    }
}