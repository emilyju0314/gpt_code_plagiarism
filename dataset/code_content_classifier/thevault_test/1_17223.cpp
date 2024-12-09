VREF CvtToVRef(VNUM hOldVnum)
{
    Area*   nArea       = CvtFindArea(hOldVnum);
    if(!nArea)
        return MakeVRef(0,0);

    VNUM    nAnum       = nArea->mANum;
    VNUM    nSubVnum    = hOldVnum - nArea->mMinOldVnum;

    return MakeVRef(nAnum, nSubVnum);
}