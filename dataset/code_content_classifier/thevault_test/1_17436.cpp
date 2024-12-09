void XPMPGetModelInfo(int inIndex, const char **outModelName, const char **outIcao, const char **outAirline, const char **outLivery)
{
    // sanity check: index too high?
    if (inIndex >= XPMPGetNumberOfInstalledModels()) {
        LOG_MSG(logDEBUG, "inIndex %d too high, have only %d models",
                inIndex, (int)XPMPGetNumberOfInstalledModels());
        return;
    }
    
    // get the inIndex-th model
    mapCSLModelTy::const_iterator iterMdl = glob.mapCSLModels.cbegin();
    std::advance(iterMdl, inIndex);
#if _MSC_VER
#pragma warning(push)
    // I don't know why, but in this function, and only in this, MS warns about throwing an exception
#pragma warning(disable: 4297)
#endif
    LOG_ASSERT(iterMdl != glob.mapCSLModels.cend());
#if _MSC_VER
#pragma warning(pop)
#endif

    // Copy string pointers back. We just pass back pointers into our CSL Model object
    // as we can assume that the CSL Model object exists quite long.
    const CSLModel& csl = iterMdl->second;
    if (outModelName)   *outModelName   = csl.GetId().data();
    if (outIcao)        *outIcao        = csl.GetIcaoType().data();
    if (outAirline)     *outAirline     = csl.GetIcaoAirline().data();
    if (outLivery)      *outLivery      = csl.GetLivery().data();
}