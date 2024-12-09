XPMPPlaneCallbackResult CBPlaneData (XPMPPlaneID         inPlane,
                                     XPMPPlaneDataType   inDataType,
                                     void *              ioData,
                                     void *              /* inRefcon */)
{
    // sanity check: our plane?
    if (inPlane != hStdPlane) return xpmpData_Unavailable;

    // There is 4 requests to deal with
    switch (inDataType) {
        case xpmpDataType_Position:
            return SetPositionData (*(XPMPPlanePosition_t*)ioData);
        case xpmpDataType_Surfaces:
            return SetSurfaceData(*(XPMPPlaneSurfaces_t*)ioData);
        case xpmpDataType_Radar:
            return SetRadarData(*(XPMPPlaneRadar_t*)ioData);
        case xpmpDataType_InfoTexts:
            return SetInfoData(*(XPMPInfoTexts_t*)ioData);
        default:
            return xpmpData_Unavailable;
    }
}