void ClientToggleActive (int nForce)
{
    // Need to start?
    if (nForce > 0 ||
        XPMP2::RemoteGetStatus() == XPMP2::REMOTE_OFF)
    {
        // Try already to get TCAS control so we have it before others can snatch it away.
        // This is not in accordance with what is laid out in "TCAS Override"
        // https://developer.x-plane.com/article/overriding-tcas-and-providing-traffic-information/#Plugin_coordination
        // but we serve a good deed here: We can combine several plugins' TCAS needs,
        // but only if we are in control:
        ClientTryGetAI();

        // Start the listener to receive message
        XPMP2::RemoteCBFctTy rmtCBFcts = {
            ClientFlightLoopBegins,         // before flight loop processing starts
            ClientFlightLoopEnds,           // after flight loop processing ends
            ClientProcSettings,             // Settings
            ClientProcAcDetails,            // Aircraft Details
            ClientProcAcPosUpdate,          // Aircraft Position Update
            ClientProcAcAnim,               // Aircraft Animarion dataRef values
            ClientProcAcRemove,             // Aircraft Removal
        };
        XPMP2::RemoteRecvStart(rmtCBFcts);
    }
    // Need to stop?
    else if (nForce < 0 ||
             XPMP2::RemoteGetStatus() != XPMP2::REMOTE_OFF)
    {
        // Release the data access lock, just a safety measure so that we don't hinder shutdown in case we f--- up
        try { glockDataMain.unlock(); }
        catch (...) { /* ignore all errors */ }
        // Stop the listener
        XPMP2::RemoteRecvStop();
        // Shut down everything
        ClientReleaseAI();
        rcGlob.gmapSender.clear();      // removes aircraft in turn
        LOG_MSG(logINFO, INFO_DEACTIVATED);
    }
}