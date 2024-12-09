Spectrum GlitteringConductorReflection::f(const Vector3f &wo,
                                          const Vector3f &wi) const {
    VLOG(1) << "wo.z: " << wo.z
            << " -> number of microfacets within ray footprint: "
            << GetNMicrofacetWithinP(st, dstdx, dstdy);

    Float cosThetaO = CosTheta(wo), cosThetaI = CosTheta(wi);
    Vector3f wh = wi + wo;
    // Handle degenerate cases for microfacet reflection
    if (cosThetaI <= 0 || cosThetaO <= 0) return Spectrum(0.);
    if (wh.x == 0 && wh.y == 0 && wh.z <= 0) return Spectrum(0.);

    wh = Normalize(wh);

    // Local masking shadowing
    if (Dot(wo, wh) <= 0. || Dot(wi, wh) <= 0.) return Spectrum(0.);

    float D_P_value = D_P(wh, st, dstdx, dstdy);

    Spectrum F = fresnel->Evaluate(Dot(wi, Faceforward(wh, Vector3f(0, 0, 1))));

    Float G1wowh = G1VCavity(wh, wo);
    Float G1wiwh = G1VCavity(wh, wi);
    float G = G1wowh * G1wiwh;

    return R * (F * G * D_P_value) / (4. * wo.z * wi.z);
}