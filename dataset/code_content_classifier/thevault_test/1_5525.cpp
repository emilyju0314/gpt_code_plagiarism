Float GlitteringConductorReflection::Visible_D_P(const Vector3f &wm,
                                                 const Vector3f &wo) const {
    Float dotWOWM = Dot(wo, wm);
    // Back facing surfaces return 0
    if (dotWOWM <= 0. || wo.z <= 0. || wm.z <= 0.) return 0.;
    // P-NDF value
    Float D_PValue = D_P(wm, st, dstdx, dstdy);
    // P-VNDF value
    Float density = G1VCavity(wm, wo) * dotWOWM * D_PValue / wo.z;
    return density;
}