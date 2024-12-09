void RemoteAC::UpdatePosition (float _elapsed, int)
{
    // Did the CSL model change?
    if (bCSLModelChanged) {
        bCSLModelChanged = false;
        XPMP2::CSLModel *pNewCSLModel = XPMP2::CSLModelByPkgShortId(pkgHash, sShortId);
        if (pNewCSLModel && pNewCSLModel != pCSLMdl)
            AssignModel("", pNewCSLModel);
    }
    
    // If we have a fresh world position then that's the one that counts
    if (bWorldCoordUpdated) {
        SetLocation(lat, lon, alt_ft);      // Convert to local, stored in drawInfo
        bWorldCoordUpdated = false;

        // cycle the historic positions and save the new one
        histPos[0] = histPos[1];
        histPos[1] = drawInfo;
        // Timestamp: This one [1] is valid _now_
        histTs[1]  = nowFlightLoop;
        histTs[0]  = histTs[1] - diffTime;

        // Special handling for heading as [0] and [1] could be on different sides of 0 / 360 degrees:
        // We push things towards positive figures larger than 360
        // as we can then just use fmod(h,360) and don't care about negatives
        if (histPos[0].heading >= 360.0f)       // if we increased the value last time we need to normalize it before re-calculation
            histPos[0].heading -= 360.0f;
        const float diffHead = histPos[0].heading - histPos[1].heading;
        if (diffHead > 180.0f)
            histPos[1].heading += 360.0f;
        else if (diffHead < -180.0f)
            histPos[0].heading += 360.0f;
    }
    // extrapolate based on last 2 positions if 2 positions are known with differing timestamps
    else if (!std::isnan(histPos[0].x) && histTs[1] > histTs[0]) {
        const std::chrono::steady_clock::duration dHist = histTs[1] - histTs[0];
        const std::chrono::steady_clock::duration dNow = nowFlightLoop - histTs[0];
        
        // We extrapolate only for a maximum of 1s, after that planes just stop
        // (If the sender is, e.g., stuck in an X-Plane dialog then that sender
        //  will not send position updates, so stopping is fairly close to reality.)
        if (dNow - dHist <= std::chrono::seconds(1)) {
            try {
                const float f = float(dNow.count()) / float(dHist.count());
                drawInfo.x       = histPos[0].x       + f * (histPos[1].x       - histPos[0].x);
                drawInfo.y       = histPos[0].y       + f * (histPos[1].y       - histPos[0].y);
                drawInfo.z       = histPos[0].z       + f * (histPos[1].z       - histPos[0].z);
                drawInfo.pitch   = histPos[0].pitch   + f * (histPos[1].pitch   - histPos[0].pitch);
                drawInfo.heading = std::fmod(histPos[0].heading + f * (histPos[1].heading - histPos[0].heading), 360.0f);
                drawInfo.roll    = histPos[0].roll    + f * (histPos[1].roll    - histPos[0].roll);

/*                    LOG_MSG(logDEBUG, "0x%06X: %.2f / %.2f / %.2f  ==> %+8.2f / %+8.2f / %+8.2f  [%.4f]",
                            GetModeS_ID(), drawInfo.x, drawInfo.y, drawInfo.z,
                            drawInfo.x-prevDraw.x,
                            drawInfo.y-prevDraw.y,
                            drawInfo.z-prevDraw.z, f); */
            }
            catch (...) {
                drawInfo = histPos[1];
            }
        } else {
            // This plane has no updates...but the sender is updated?
            // Then we lost contact to this plane and shall remove it
            if (nowFlightLoop - sender.lastMsg < std::chrono::milliseconds(500)) {
                LOG_MSG(logWARN, WARN_LOST_PLANE_CONTACT, senderId,
                        (int)sizeof(sender.settings.name), sender.settings.name,
                        sender.settings.pluginId, sender.sFrom.c_str());
                SetInvalid();
            }
        }
    }
    
    // Special handling for rotational dataRefs:
    // These are the only ones we move ourselves as they need to keep going every frame
    // for good looks.
    // Idea: Turn them based on defined speed
    if (GetTireRotRpm() > 1.0f) SetTireRotAngle(std::fmod(GetTireRotAngle() + GetTireRotRpm()/60.0f * _elapsed * 360.0f, 360.0f));
    if (GetEngineRotRpm() > 1.0f) SetEngineRotAngle(std::fmod(GetEngineRotAngle() + GetEngineRotRpm()/60.0f * _elapsed * 360.0f, 360.0f));
    for (size_t i = 1; i <= 4; i++)
        if (GetEngineRotRpm(i) > 1.0f) SetEngineRotAngle(i, std::fmod(GetEngineRotAngle(i) + GetEngineRotRpm(i)/60.0f * _elapsed * 360.0f, 360.0f));
    if (GetPropRotRpm() > 1.0f) SetPropRotAngle(std::fmod(GetPropRotAngle() + GetPropRotRpm()/60.0f * _elapsed * 360.0f, 360.0f));
}