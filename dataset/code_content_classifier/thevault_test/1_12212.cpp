bool IntersectSegmentCylinder(
        const AZ::Vector3& sa, const AZ::Vector3& sb, const AZ::Vector3& p, const AZ::Vector3& q, float r, float& t)
    {
        // clang-format off
        const AZ::Vector3 d = q - p;
        const AZ::Vector3 m = sa - p;
        const AZ::Vector3 n = sb - sa;

        const float md = m.Dot(d);
        const float nd = n.Dot(d);
        const float dd = d.Dot(d);

        if (md < 0.0f && md + nd < 0.0f) return false;
        if (md > dd && md + nd > dd) return false;
        const float nn = n.Dot(n);
        const float mn = m.Dot(n);
        const float a = dd * nn - nd * nd;
        const float k = m.Dot(m) - r * r;
        const float c = dd * k - md * md;
        if (AZ::GetAbs(a) < AZ::Constants::FloatEpsilon) {
            if (c > 0.0f) return false;
            if (md < 0.0f) t = -mn / nn;
            else if (md > dd) t = -mn / nn;
            else t = 0.0f;
            return true;
        }
        const float b = dd * mn - nd * md;
        const float discr = b * b - a * c;
        if (discr < 0.0f) return false;
        t = (-b - sqrt(discr)) / a;
        if (t < 0.0f || t > 1.0f) return false;
        if (md + t * nd < 0.0f) {
            if (nd <= 0.0f) return false;
            t = -md / nd;
            return k + 2 * t * (mn + t * nn) <= 0.0f;
        }
        else if (md + t * nd > dd) {
            if (nd >= 0.0f) return false;
            t = (dd - md) / nd;
            return k + dd - 2 * md + t * (2 * (mn - nd) + t * nn) <= 0.0f;
        }
        return true;
        // clang-format on
    }