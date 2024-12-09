void RemoteAC::Update (const XPMP2::RemoteAcDetailTy& _acDetails)
{
    acIcaoType      = STR_N(_acDetails.icaoType);
    acIcaoAirline   = STR_N(_acDetails.icaoOp);
    acLivery.clear();

    // CSL Model: Did it change? (Will be set during UpdatePosition())
    bCSLModelChanged = (pkgHash != _acDetails.pkgHash) || (sShortId != _acDetails.sShortId);
    if (bCSLModelChanged) {
        pkgHash  = _acDetails.pkgHash;
        sShortId = _acDetails.sShortId;
    }
    
    label = STR_N(_acDetails.label);
    _acDetails.GetLabelCol(colLabel);

    // We might be in a worker thread...only temporarily store the position
    lat = _acDetails.lat;
    lon = _acDetails.lon;
    alt_ft = double(_acDetails.alt_ft);
    diffTime = std::chrono::duration<int,std::ratio<1, 10000>>(_acDetails.dTime);
    bWorldCoordUpdated = true;          // flag for UpdatePosition() to read fresh data

    drawInfo.pitch      = _acDetails.GetPitch();
    drawInfo.heading    = _acDetails.GetHeading();
    drawInfo.roll       = _acDetails.GetRoll();
    aiPrio              = _acDetails.aiPrio;
    
    // Info texts
#if defined(__GNUC__) && (__GNUC__ >= 9)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wclass-memaccess"
#endif
    std::memset(&acInfoTexts, 0, sizeof(acInfoTexts));
#if defined(__GNUC__) && (__GNUC__ >= 9)
#pragma GCC diagnostic pop
#endif
#define memcpy_min(to,from) std::memcpy(to,from,std::min(sizeof(from),sizeof(to)))
    memcpy_min(acInfoTexts.tailNum,         _acDetails.tailNum);
    memcpy_min(acInfoTexts.icaoAcType,      _acDetails.icaoType);
    memcpy_min(acInfoTexts.manufacturer,    _acDetails.manufacturer);
    memcpy_min(acInfoTexts.model,           _acDetails.model);
    memcpy_min(acInfoTexts.icaoAirline,     _acDetails.icaoOp);
    memcpy_min(acInfoTexts.airline,         _acDetails.airline);
    memcpy_min(acInfoTexts.flightNum,       _acDetails.flightNum);
    memcpy_min(acInfoTexts.aptFrom,         _acDetails.aptFrom);
    memcpy_min(acInfoTexts.aptTo,           _acDetails.aptTo);

    // Don't render local planes (the local plugin does already),
    // or if explicitely instructed so by the sender
    SetRender(sender.bLocal ? false : _acDetails.bRender);

    // Validity and Visibility
    SetVisible(_acDetails.bVisible);
    if (!_acDetails.bValid)
        SetInvalid();
    
    // Animation dataRefs
    for (size_t i = 0; i < XPMP2::V_COUNT; ++i)
        v[i] = XPMP2::REMOTE_DR_DEF[i].unpack(_acDetails.v[i]);
/*
    LOG_MSG(logDEBUG, " 0x%06X: %.7f / %.7f, %.1f",
            GetModeS_ID(), lat, lon, alt_ft);*/
}