Spectrum GlitteringConductorReflection::Sample_f(const Vector3f &wo,
                                                 Vector3f *wi, const Point2f &u,
                                                 Float *pdf,
                                                 BxDFType *sampledType) const {
    // Sample microfacet orientation $\wh$ and reflected direction $\wi$
    if (wo.z <= 0) return 0.;
    Vector3f wh;
    if (sampleVisibleArea)
        wh = Sample_Visible_D_P(wo);
    else
        wh = Sample_D_P();
    Float dotWOWM = Dot(wo, wh);
    // We cannot reflect with a back facing normal
    if (dotWOWM <= 0.) return 0.;

    *wi = Reflect(wo, wh);
    if (wi->z <= 0.) return 0.;

    // Compute PDF of _wi_ for microfacet reflection
    Spectrum F =
        fresnel->Evaluate(Dot(*wi, Faceforward(wh, Vector3f(0, 0, 1))));
    if (sampleVisibleArea) {
        //---------------------------------------------------------------------
        // PDF value
        Float visible_D_P = 0.;
        if (!sampleApproximation) {
            visible_D_P = Visible_D_P(wh, wo);
            *pdf = visible_D_P / (4 * Dot(wo, wh));
        } else {
            Vector2f slopeH(-wh.x / wh.z, -wh.y / wh.z);
            Float D_PValue = SDFLastLOD(slopeH) / (wh.z * wh.z * wh.z * wh.z);
            Float density = G1VCavity(wh, wo) * dotWOWM * D_PValue / wo.z;
            Float visible_D_PApprox = density;
            *pdf = visible_D_PApprox / (4 * Dot(wo, wh));
        }
        //---------------------------------------------------------------------

        //---------------------------------------------------------------------
        // BRDF value
        Spectrum BRDFValue;
        // We have already compute D_P
        if (!sampleApproximation)
            BRDFValue = R * visible_D_P * G1VCavity(wh, *wi) * F /
                        (4. * Dot(wo, wh) * wi->z);
        // We do not have already compute D_P
        else
            BRDFValue = R * D_P(wh, st, dstdx, dstdy) * G1VCavity(wh, wo) *
                        G1VCavity(wh, *wi) * F / (4. * wo.z * wi->z);
        return BRDFValue;
        //---------------------------------------------------------------------
    } else {
        //---------------------------------------------------------------------
        // PDF value
        Float D_PValue;
        if (!sampleApproximation) {
            D_PValue = D_P(wh, st, dstdx, dstdy);
            *pdf = D_PValue * wh.z / (4 * Dot(wo, wh));
        } else {
            Vector2f slopeH(-wh.x / wh.z, -wh.y / wh.z);
            Float D_PValueApprox =
                SDFLastLOD(slopeH) / (wh.z * wh.z * wh.z * wh.z);
            *pdf = D_PValueApprox * wh.z / (4 * Dot(wo, wh));
        }
        //---------------------------------------------------------------------

        //---------------------------------------------------------------------
        // BRDF value
        Float G1wowh = G1VCavity(wh, wo);
        Float G1wiwh = G1VCavity(wh, *wi);
        float G = G1wowh * G1wiwh;

        Spectrum BRDFValue;
        // We have already compute D_P
        if (!sampleApproximation)
            BRDFValue = R * D_PValue * G * F / (4. * wo.z * wi->z);
        // We do not have already compute D_P
        else
            BRDFValue =
                R * D_P(wh, st, dstdx, dstdy) * G * F / (4. * wo.z * wi->z);
        return BRDFValue;
        //---------------------------------------------------------------------
    }
}