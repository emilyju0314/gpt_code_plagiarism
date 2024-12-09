static SkPoint sanitize_point(const SkPoint& in) {
    SkPoint out;
    out.fX = SkScalarRoundToScalar(16.f*in.fX)*0.0625f;
    out.fY = SkScalarRoundToScalar(16.f*in.fY)*0.0625f;
    return out;
}