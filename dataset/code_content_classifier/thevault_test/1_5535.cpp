Float GlitteringConductorReflection::Pdf(const Vector3f &wo,
                                         const Vector3f &wi) const {
    if (wo.z <= 0. || wi.z <= 0.) return 0.;
    Vector3f wh = Normalize(wo + wi);
    Float pdf;
    Float dotWOWM = Dot(wo, wh);
    // Should be very rare
    if (dotWOWM <= 0.) return 0.;
    if (sampleVisibleArea) {
        if (!sampleApproximation)
            pdf = Visible_D_P(wh, wo) / (4 * Dot(wo, wh));
        else {
            Vector2f slopeH(-wh.x / wh.z, -wh.y / wh.z);
            Float D_PValue = SDFLastLOD(slopeH) / (wh.z * wh.z * wh.z * wh.z);
            Float density = G1VCavity(wh, wo) * dotWOWM * D_PValue / wo.z;
            Float visible_D_PApprox = density;
            pdf = visible_D_PApprox / (4 * Dot(wo, wh));
        }
    } else {
        if (!sampleApproximation)
            pdf = D_P(wh, st, dstdx, dstdy) * wh.z / (4 * Dot(wo, wh));
        else {
            Vector2f slopeH(-wh.x / wh.z, -wh.y / wh.z);
            Float D_PValueApprox =
                SDFLastLOD(slopeH) / (wh.z * wh.z * wh.z * wh.z);
            pdf = D_PValueApprox * wh.z / (4 * Dot(wo, wh));
        }
    }
    return pdf;
}