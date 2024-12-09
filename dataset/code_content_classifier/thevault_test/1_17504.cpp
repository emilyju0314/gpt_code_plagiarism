void ClientFlightLoopBegins ()
{
    // Any main thread stuff to do due to settings updates?
    if (!gbSkipSettingsUpdate.test_and_set()) {
        XPMPEnableMap(rcGlob.mergedS.bMapEnabled,
                      rcGlob.mergedS.bMapLabels);
        if (rcGlob.mergedS.bHaveTCASControl)
            ClientTryGetAI();
    }
    
    // Store current time once for all position calculations
    nowFlightLoop = std::chrono::steady_clock::now();

    // Acquire the data access lock once and keep it while the flight loop is running
    if (!glockDataMain)
        glockDataMain.lock();
    
    // Every 10 seconds clean up outdated senders
    static float lastSenderCleanup = 0;
    if (GetMiscNetwTime() - lastSenderCleanup > 10.0f) {
        lastSenderCleanup = GetMiscNetwTime();
        for (mapSenderTy::iterator sIter = rcGlob.gmapSender.begin();
             sIter != rcGlob.gmapSender.end();)
        {
            const SenderTy& sdr = sIter->second;
            if (nowFlightLoop - sdr.lastMsg > std::chrono::seconds(2 * XPMP2::REMOTE_SEND_SETTINGS_INTVL)) {
                LOG_MSG(logINFO, INFO_SENDER_PLUGIN_LOST,
                        (int)sizeof(sdr.settings.name), sdr.settings.name,
                        sdr.settings.pluginId, sdr.sFrom.c_str());
                sIter = rcGlob.gmapSender.erase(sIter);
            }
            else
                sIter++;
        }
    }

    // If needed create new or remove deleted aircraft that have been prepared in the meantime
    if (gbSkipAcMaintenance.test_and_set()) {
        for (auto& s: rcGlob.gmapSender) {              // loop all senders
            // loop all a/c of that sender
            mapRemoteAcTy::iterator acIter = s.second.mapAc.begin();
            while (acIter != s.second.mapAc.end()) {
                // a/c to be deleted?
                if (acIter->second.IsToBeDeleted())
                    acIter = s.second.mapAc.erase(acIter);
                // create a/c if not created
                else if (acIter->second.GetModeS_ID() == 0)
                    (acIter++)->second.Create();
                else
                    acIter++;
            }
        }
    }
}