void XPMPDestroyPlane(XPMPPlaneID _id)
{
    Aircraft* pAc = AcFindByID(_id);
    if (pAc)
        delete pAc;
}