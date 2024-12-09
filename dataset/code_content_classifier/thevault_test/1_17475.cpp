XPMPPlaneID GlobVars::NextPlaneId ()
{
    // increment until we find an unused number
    bool bWrappedAround = false;
    while (mapAc.count(++planeId) != 0) {
        if (planeId >= MAX_MODE_S_ID) {
            if (bWrappedAround)         // we already wrapped around once and found nothing free???
                THROW_ERROR("Found no available mode S id!!!");
            bWrappedAround = true;
            planeId = MIN_MODE_S_ID - 1;
        }
    }
    // found something, which is not yet taken, return it:
    return planeId;
}