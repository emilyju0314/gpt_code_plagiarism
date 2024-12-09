void XPMPGetPlaneICAOAndLivery(XPMPPlaneID inPlane,
                               char *      outICAOCode,    // Can be NULL
                               char *      outLivery)      // Can be NULL
{
    Aircraft* pAc = AcFindByID(inPlane);
    if (pAc) {
        // this is not a safe operation...but the way the legay interface was defined:
        if (outICAOCode) strcpy (outICAOCode, pAc->acIcaoType.c_str());
        if (outLivery)   strcpy (outLivery,   pAc->acLivery.c_str());
    }
}