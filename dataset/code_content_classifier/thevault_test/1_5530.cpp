Vector2f GlitteringConductorReflection::Sample_P22_M(int l, uint64_t s0,
                                                     uint64_t t0,
                                                     Float lDist) const {
    // Coherent index
    uint64_t s064 = s0 * 1 << l;
    uint64_t t064 = t0 * 1 << l;

    // https://en.wikipedia.org/wiki/Pairing_function#Cantor_pairing_function
    uint64_t seed = ((s064 + t064) * (s064 + t064 + 1)) / 2 + t064;

    // Seed pseudo random generator to retrieve cell material properties
    // (microfacet relative area, density randomisation, marginal distributions)
    rngEval->SetSequence(seed);

    // Recover RMS roughness
    Float sigmaX = alphaXGlitteringMaterial / Sqrt2;
    Float sigmaY = alphaYGlitteringMaterial / Sqrt2;

    // If the current cell has no microfacets, a default material is sampled
    Float uMicrofacetRelativeArea = rngEval->UniformFloat();
    if (uMicrofacetRelativeArea > microfacetRelativeArea) {
        Point2f uSampling(rngSample->UniformFloat(), rngSample->UniformFloat());
        return SampleBivariateNormalDistribution(
            uSampling, alphaXBaseMaterial, alphaYBaseMaterial, rhoBaseMaterial);
    }

    // Sample a Gaussian to randomise the distribution LOD around the
    // distribution level lDist
    Float uDensityRandomisation = rngEval->UniformFloat();
    lDist = SampleNormalDistribution(uDensityRandomisation, lDist,
                                     densityRandomisation);
    int iLDist = Clamp(int(std::round(lDist)), 0, nLevels);

    // If the current distribution level is greater than or equal to nLevels,
    // then the SDF of the last LOD is sampled
    if (iLDist == nLevels) {
        return SampleSDFLastLOD();
    }

    // Linear transformation represented by matrix M
    Float SIGMA_DICT = alphaDict / Sqrt2;
    Float M00 = 1. / SIGMA_DICT *
                (sigmaX *
                 std::sqrt(1. - rhoGlitteringMaterial * rhoGlitteringMaterial));
    Float M01 = 1. / SIGMA_DICT * rhoGlitteringMaterial * sigmaX;
    Float M10 = 0.;
    Float M11 = 1. / SIGMA_DICT * sigmaY;

    // Samples a random rotation to disalign the glints
    Float uTheta = rngEval->UniformFloat();
    Float theta = 2. * Pi * uTheta;
    Float cosTheta = std::cos(theta);
    Float sinTheta = std::sin(theta);

    // Linear transformation represented by matrix MR
    // (incorporate a random rotation)
    Float MR00 = cosTheta * M00 + sinTheta * M01;
    Float MR01 = -sinTheta * M00 + cosTheta * M01;
    Float MR10 = cosTheta * M10 + sinTheta * M11;
    Float MR11 = -sinTheta * M10 + cosTheta * M11;

    // Compute the indices of the two marginal distributions
    Float u1 = rngEval->UniformFloat();
    Float u2 = rngEval->UniformFloat();
    int i = int(u1 * Float(N));
    int j = int(u2 * Float(N));

    // Sample original (dictionary) slope space
    Point2f uSamplingI(rngSample->UniformFloat(), rngSample->UniformFloat());
    Float slopeHXO = Sample_P(uSamplingI, i, iLDist);
    Point2f uSamplingJ(rngSample->UniformFloat(), rngSample->UniformFloat());
    Float slopeHYO = Sample_P(uSamplingJ, j, iLDist);

    // Transforms the sample
    Vector2f slopeH(slopeHXO * MR00 + slopeHYO * MR01,
                    slopeHXO * MR10 + slopeHYO * MR11);

    return slopeH;
}