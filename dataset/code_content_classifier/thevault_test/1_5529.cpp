Float GlitteringConductorReflection::P22_M(int l, uint64_t s0, uint64_t t0,
                                           const Vector2f &slopeH,
                                           Float lDist) const {
    // Coherent index between MIPMAP LODs
    uint64_t s064 = s0 * 1 << l;
    uint64_t t064 = t0 * 1 << l;

    // Cantor pairing function
    uint64_t seed = ((s064 + t064) * (s064 + t064 + 1)) / 2 + t064;

    // Seeds pseudo random generator with the coherent index
    rngEval->SetSequence(seed);

    // Recovers RMS roughness
    Float sigmaX = alphaXGlitteringMaterial / Sqrt2;
    Float sigmaY = alphaYGlitteringMaterial / Sqrt2;

    // If the current cell has no microfacets, a default material is evaluated
    // to avoid "black holes" on the surface.
    Float uMicrofacetRelativeArea = rngEval->UniformFloat();
    if (uMicrofacetRelativeArea > microfacetRelativeArea)
        return BivariateNormalDistribution(slopeH.x, slopeH.y,
                                           alphaXBaseMaterial,
                                           alphaYBaseMaterial, rhoBaseMaterial);

    // Sample a Gaussian to randomize the distribution LOD around the
    // distribution level lDist.
    Float uDensityRandomisation = rngEval->UniformFloat();
    lDist = SampleNormalDistribution(uDensityRandomisation, lDist,
                                     densityRandomisation);
    int iLDist = Clamp(int(std::round(lDist)), 0, nLevels);

    // If the current distribution level is greater than or equal to nLevels,
    // then the SDF is the SDF of the last LOD
    if (iLDist == nLevels) {
        return SDFLastLOD(slopeH);
    }

    // Inverse linear transformation represented by matrix invM
    Float SIGMA_DICT = alphaDict / Sqrt2;
    Float invM00 =
        SIGMA_DICT / (sigmaX * std::sqrt(1. - rhoGlitteringMaterial *
                                                  rhoGlitteringMaterial));
    Float invM01 = -SIGMA_DICT * rhoGlitteringMaterial /
                   (sigmaY * std::sqrt(1. - rhoGlitteringMaterial *
                                                rhoGlitteringMaterial));
    Float invM10 = 0.;
    Float invM11 = SIGMA_DICT / sigmaY;

    // Samples a random rotation to disalign the glints
    Float uTheta = rngEval->UniformFloat();
    Float theta = 2. * Pi * uTheta;
    Float cosTheta = std::cos(theta);
    Float sinTheta = std::sin(theta);

    // Inverse linear transformation represented by matrix invRM
    // (incorporate a random rotation)
    Float invRM00 = cosTheta * invM00 + sinTheta * invM10;
    Float invRM01 = cosTheta * invM01 + sinTheta * invM11;
    Float invRM10 = -sinTheta * invM00 + cosTheta * invM10;
    Float invRM11 = -sinTheta * invM01 + cosTheta * invM11;

    // Get back to original (dictionary) slope space
    Vector2f slopeHO(slopeH.x * invRM00 + slopeH.y * invRM01,
                     slopeH.x * invRM10 + slopeH.y * invRM11);
    // 1D distribution are even functions
    Vector2f absSlopeHO(std::abs(slopeHO.x), std::abs(slopeHO.y));

    // The distribution equals 0 after 4 standard deviations.
    // Slope standard deviation = alpha / sqrt(2)
    // 0.707106 \approx 1 / sqrt(2)
    Float alpha_dist_isqrt2_4 = alphaDict * 0.707106 * 4.;
    if (absSlopeHO.x > alpha_dist_isqrt2_4 ||
        absSlopeHO.y > alpha_dist_isqrt2_4)
        return 0.;

    // Sample the two 1D distributions
    Float u1 = rngEval->UniformFloat();
    Float u2 = rngEval->UniformFloat();
    int i = int(u1 * Float(N));
    int j = int(u2 * Float(N));

    // Evaluate the two 1D distributions in the original space
    Float P_i = P(absSlopeHO.x, i, iLDist);
    Float P_j = P(absSlopeHO.y, j, iLDist);

    // The value of the transformed SDF
    return SIGMA_DICT * SIGMA_DICT * P_i * P_j /
           (sigmaX * sigmaY *
            std::sqrt(1. - rhoGlitteringMaterial * rhoGlitteringMaterial));
}