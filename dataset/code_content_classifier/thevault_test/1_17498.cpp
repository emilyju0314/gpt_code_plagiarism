void RemoteAC::Update (const XPMP2::RemoteAcPosUpdateTy& _acPosUpd)
{
    // Update position information based on diff values in the position update
    lat     += XPMP2::REMOTE_DEGREE_RES * double(_acPosUpd.dLat);
    lon     += XPMP2::REMOTE_DEGREE_RES * double(_acPosUpd.dLon);
    alt_ft  += XPMP2::REMOTE_ALT_FT_RES * double(_acPosUpd.dAlt_ft);
    diffTime = std::chrono::duration<int,std::ratio<1, 10000>>(_acPosUpd.dTime);
    bWorldCoordUpdated = true;          // flag for UpdatePosition() to read fresh data

    drawInfo.pitch      = _acPosUpd.GetPitch();
    drawInfo.heading    = _acPosUpd.GetHeading();
    drawInfo.roll       = _acPosUpd.GetRoll();
/*
    LOG_MSG(logDEBUG, "0x%06X: %.7f / %.7f, %.1f  <-- %+.7f / %+.7f, %+.1f",
            GetModeS_ID(), lat, lon, alt_ft,
            _acPosUpd.dLat * XPMP2::REMOTE_DEGREE_RES,
            _acPosUpd.dLon * XPMP2::REMOTE_DEGREE_RES,
            _acPosUpd.dAlt_ft * XPMP2::REMOTE_ALT_FT_RES); */
}