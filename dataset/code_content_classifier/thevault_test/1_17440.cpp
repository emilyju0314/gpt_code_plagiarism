void XPMPSetPlaneVisibility(XPMPPlaneID _id, bool _bVisible)
{
    Aircraft* pAc = AcFindByID(_id);
    if (pAc)
        pAc->SetVisible(_bVisible);
}