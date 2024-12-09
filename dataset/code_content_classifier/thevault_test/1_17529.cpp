void AcTxtLine_OBJECT_AIRCRAFT (CSLModel& csl,
                                const std::string& /*ln*/,
                                int /*lnNr*/)
{
    // First of all, save the previously read aircraft
    if (csl.IsValid())
        CSLModelsAdd(csl);

    // Then add a warning into the log as we will NOT support this model
    // Could be too many and clog up the log - LOG_MSG(logWARN, WARN_OBJ8_ONLY, lnNr, ln.c_str());
}