void XPMPSetAircraftLabelDist (float _dist_nm, bool _bCutOffAtVisibility)
{
    glob.bLabelCutOffAtVisibility = _bCutOffAtVisibility;
    glob.maxLabelDist = std::max(_dist_nm,1.0f) * M_per_NM; // store in meter
}