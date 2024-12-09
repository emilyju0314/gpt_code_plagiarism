RemoteAC::RemoteAC (SenderTy& _sender, const XPMP2::RemoteAcDetailTy& _acDetails) :
XPMP2::Aircraft(),              // do _not_ create an actual plane!
senderId(_acDetails.modeS_id),
pkgHash(_acDetails.pkgHash),
sShortId(STR_N(_acDetails.sShortId)),
sender(_sender)
{
    // Initialization
    histPos[0] = {sizeof(XPLMDrawInfo_t), NAN, NAN, NAN, 0.0f, 0.0f, 0.0f};
    histPos[1] = histPos[0];
    
    // store the a/c detail information
    Update(_acDetails);
}