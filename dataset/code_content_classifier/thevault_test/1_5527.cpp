Vector3f GlitteringConductorReflection::Sample_Visible_D_P(
    const Vector3f &wo) const {
    // See Heitz and d'Eon 2014 for more details

    // Samples the NDF
    Vector3f wm = Sample_D_P();

    // Computes the dual of the sampled micronormal (the other facet of the
    // V-cavity)
    Vector3f wmP(-wm.x, -wm.y, wm.z);
    // Just in case
    CHECK_GT(wm.z, 0.);

    Float dotWOWMP = std::max(Dot(wo, wmP), Float(0.));
    Float dotWOWM = std::max(Dot(wo, wm), Float(0.));
    Float deno = dotWOWM + dotWOWMP;
    // Just in case
    CHECK_GT(deno, 0.);
    // Projected area of the other facet of the V-cavity
    Float projectedAreaWMP = dotWOWMP / deno;
    // Samples a facet of the V-cavity
    if (rngSample->UniformFloat() < projectedAreaWMP)
        return wmP;
    else
        return wm;
}