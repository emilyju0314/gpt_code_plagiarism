void XPMPSendNotification (const Aircraft& plane, XPMPPlaneNotification _notification)
{
    for (const XPMPPlaneNotifierTy& n: glob.listObservers)
        n.func(plane.GetModeS_ID(),
               _notification,
               n.refcon);
}