int     XPMPChangePlaneModel(XPMPPlaneID            _id,
                             const char *           inICAO,
                             const char *           inAirline,
                             const char *           inLivery)
{
    Aircraft* pAc = AcFindByID(_id);
    if (pAc)
        return pAc->ChangeModel(inICAO      ? inICAO : "",
                                inAirline   ? inAirline : "",
                                inLivery    ? inLivery : "");
    else
        return -1;
}