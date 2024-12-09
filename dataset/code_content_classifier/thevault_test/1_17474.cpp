float FlightLoopCallback(float, float, int, void*)
{
    // entry point into plugin...catch exceptions latest here
    try {
        GetMiscNetwTime();              // update rcGlob.now, e.g. for logging from worker threads
        // if there aren't any planes yet then the XPMP2 library won't call ClientFlightLoopBegins(), instead we do
        if (XPMPCountPlanes() == 0) {
            try {
                // The first plane(s) would be instanciated here, and that could fail, e.g. if there are no CSL models installed
                ClientFlightLoopBegins();
            }
            catch (const std::exception& e) {
                LOG_MSG(logFATAL, ERR_EXCEPTION, e.what());
            }
            ClientFlightLoopEnds();
        }
        MenuUpdateCheckmarks();         // update menu
        MenuUpdateSenders();
    }
    catch (const std::exception& e) {
        LOG_MSG(logFATAL, ERR_EXCEPTION, e.what());
    }
    
    // call me every second only
    return 1.0f;
}