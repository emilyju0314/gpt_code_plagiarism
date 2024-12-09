void GlobVars::UpdateCfgVals ()
{
    // Let's do the update only about every 2 seconds
    static float timLstCheck = 0.0f;
    if (!CheckEverySoOften(timLstCheck, 2.0f))
        return;
    
    LOG_ASSERT(prefsFuncInt);
    
    // Ask for logging level
    int i = prefsFuncInt(XPMP_CFG_SEC_DEBUG, XPMP_CFG_ITM_LOGLEVEL, logLvl);
    if (i < logDEBUG) i = logDEBUG;
    if (i > logMSG) i = logMSG;
    logLvl = logLevelTy(i);
    
    // Ask for replacing dataRefs in OBJ8 files
    bObjReplDataRefs = prefsFuncInt(XPMP_CFG_SEC_MODELS, XPMP_CFG_ITM_REPLDATAREFS, bObjReplDataRefs) != 0;
    
    // Ask for replacing textures in OBJ8 files
    bObjReplTextures = prefsFuncInt(XPMP_CFG_SEC_MODELS, XPMP_CFG_ITM_REPLTEXTURE, bObjReplTextures) != 0;
    
    // Ask for clam-to-ground config
    bClampAll = prefsFuncInt(XPMP_CFG_SEC_PLANES, XPMP_CFG_ITM_CLAMPALL, bClampAll) != 0;
    
    // Ask for handling of duplicate XPMP2::Aircraft::modeS_id
    bHandleDupId = prefsFuncInt(XPMP_CFG_SEC_PLANES, XPMP_CFG_ITM_HANDLE_DUP_ID, bHandleDupId) != 0;

    // Ask for remote support
    i = prefsFuncInt(XPMP_CFG_SEC_PLANES, XPMP_CFG_ITM_SUPPORT_REMOTE, remoteCfg);
    if (i == 0)     remoteCfg = remoteCfgFromIni;       // if plugin says "AUTO", then use config file's value
    else if (i < 0) remoteCfg = REMOTE_CFG_OFF;
    else            remoteCfg = REMOTE_CFG_ON;

    // Ask for model matching logging
    bLogMdlMatch = prefsFuncInt(XPMP_CFG_SEC_DEBUG, XPMP_CFG_ITM_MODELMATCHING, bLogMdlMatch) != 0;
    
    // Fetch the network / multiplayer setup from X-Plane, which theoretically can change over time
    static XPLMDataRef drIsExternalVisual       = XPLMFindDataRef("sim/network/dataout/is_external_visual");        // int/boolean
    static XPLMDataRef drIsMultiplayer          = XPLMFindDataRef("sim/network/dataout/is_multiplayer_session");    // int/boolean
    static XPLMDataRef drTrackExternalVisual    = XPLMFindDataRef("sim/network/dataout/track_external_visual");     // int[20]/boolean
    const bool bWasNetworkedSetup = bXPNetworkedSetup;
    bXPNetworkedSetup = false;
    if (XPLMGetDatai(drIsExternalVisual)) {
        if (!bWasNetworkedSetup) LOG_MSG(logINFO, "This X-Plane instance is configured as an External Visual.");
        bXPNetworkedSetup = true;
    }
    else if (XPLMGetDatai(drIsMultiplayer)) {
        if (!bWasNetworkedSetup) LOG_MSG(logINFO, "This X-Plane instance is part of a multiplayer session.");
        bXPNetworkedSetup = true;
    }
    else {
        static int aNull[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int ai[20];
        XPLMGetDatavi(drTrackExternalVisual, ai, 0, sizeof(ai)/sizeof(ai[0]));
        if (std::memcmp(ai, aNull, sizeof(ai)) != 0) {
            if (!bWasNetworkedSetup) LOG_MSG(logINFO, "This X-Plane instance is a Master with one or more External Visuals.");
            bXPNetworkedSetup = true;
        }
        // Last thing we check: Is the XPLM2 Remote Client running?
        // Because if it is then the user clearly intended communication with it, even locally
        else {
            // Note: Finding a plugin can fail during startup depending on startup sequence!
            //       So it is never sufficient to search for a plugin once only.
            static XPLMPluginID idRemoteClient = XPLM_NO_PLUGIN_ID;
            static int nSearches = 5;           // we search up to 5 times for this reason
            if (idRemoteClient == XPLM_NO_PLUGIN_ID && nSearches-- > 0)
                idRemoteClient = XPLMFindPluginBySignature(REMOTE_SIGNATURE);
            if (idRemoteClient != XPLM_NO_PLUGIN_ID) {
                if (!bWasNetworkedSetup) LOG_MSG(logINFO, "The XPMP2 Remote Client is running locally.");
                bXPNetworkedSetup = true;
            }
        }
    }
    // Previously we were in a networked setup, but now no longer?
    if (bWasNetworkedSetup && !bXPNetworkedSetup) {
        LOG_MSG(logINFO, "This X-Plane instance is no longer in any networked setup.");
    }
    // Give the Remote module a chance to handle any changes in status
    // (which not only depends on bXPNetworkedSetup but also on number of planes)
    RemoteSenderUpdateStatus();

}