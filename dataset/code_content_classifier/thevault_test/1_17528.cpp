void AcTxtLine_OBJ8_AIRCRAFT (CSLModel& csl,
                              const std::string& ln,
                              const std::string& xsbAircraftPath,
                              const std::string& exportName,
                              int lnNr)
{
    // First of all, save the previously read aircraft
    if (csl.IsValid())
        CSLModelsAdd(csl);
    
    // Properly set the xsb_aircraft.txt location
    csl.xsbAircraftPath = xsbAircraftPath;
    csl.xsbAircraftLn   = lnNr;
    
    // Second parameter (actually we take all the rest of the line) is the short id:
    if (ln.length() >= 15) {
        csl.shortId = ln.substr(14);
        trim(csl.shortId);
        
        // sometimes (e.g. X-CSL) the name already contains a package name, that's superflous, take the last part only as short id
        std::string::size_type sepPos = csl.shortId.find_last_of(":/\\");
        if (sepPos != std::string::npos)
            csl.shortId.erase(0,sepPos+1);
        
        // save a hash value for the package name, needed for synching with remote client
        csl.pkgHash = PJWHash16(exportName.c_str());
        // full id is package name (EXPORT) plus the short id
        csl.cslId = exportName + '/' + csl.shortId;
        // human readable model name is last part of path plus short id
        csl.CompModelName();
    }
    else LOG_MSG(logERR, ERR_TOO_FEW_PARAM, lnNr, "OBJ8_AIRCRAFT", 1);
}