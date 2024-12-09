XPMPPlaneCallbackResult XPMPGetPlaneData(XPMPPlaneID,
                                         XPMPPlaneDataType,
                                         void *)
{
    LOG_MSG(logERR, "Calling this function from the outside should not be needed!");
    return xpmpData_Unavailable;
}