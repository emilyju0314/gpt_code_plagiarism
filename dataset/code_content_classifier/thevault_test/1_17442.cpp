int     XPMPGetPlaneModelName(XPMPPlaneID             inPlaneID,
                              char *                  outTxtBuf,
                              int                     outTxtBufSize)
{
    Aircraft* pAc = AcFindByID(inPlaneID);
    if (pAc) {
        std::string mdlName = pAc->GetModelName();
        if (outTxtBuf && outTxtBufSize > 0) {
            strncpy(outTxtBuf, mdlName.c_str(), (size_t)outTxtBufSize);
            outTxtBuf[outTxtBufSize-1] = 0;         // safety measure: ensure zero-termination
        }
        return (int)mdlName.length();
    } else {
        return -1;
    }
}