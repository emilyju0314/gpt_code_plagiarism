void CBPlaneNotifier(XPMPPlaneID            inPlaneID,
                     XPMPPlaneNotification  inNotification,
                     void *                 /*inRefcon*/)
{
    XPMP2::Aircraft* pAc = XPMP2::AcFindByID(inPlaneID);
    if (pAc) {
        LogMsg("XPMP2-Sample: Plane of type %s, airline %s, model %s, label '%s' %s",
               pAc->acIcaoType.c_str(),
               pAc->acIcaoAirline.c_str(),
               pAc->GetModelName().c_str(),
               pAc->label.c_str(),
               inNotification == xpmp_PlaneNotification_Created ? "created" :
               inNotification == xpmp_PlaneNotification_ModelChanged ? "changed" : "destroyed");
    }
}