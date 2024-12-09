int         XPMPGetPlaneModelQuality(XPMPPlaneID _inPlane)
{
    Aircraft* pAc = AcFindByID(_inPlane);
    if (pAc)
        return pAc->GetMatchQuality();
    else
        return -1;
}