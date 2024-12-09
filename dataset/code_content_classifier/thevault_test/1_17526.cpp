const char* CSLModelsReadPkgId (const std::string& path)
{
    // Open the xsb_aircraft.txt file
    const std::string xsbName (path + XPLMGetDirectorySeparator()[0] + XSB_AIRCRAFT_TXT);
    std::ifstream fAc (TOPOSIX(xsbName));
    if (!fAc || !fAc.is_open())
        return WARN_NO_XSBACTXT_FOUND;
    
    // read the file line by line
//    LOG_MSG(logINFO, INFO_XSBACTXT_READ, xsbName.c_str());
    while (fAc)
    {
        // read a line, trim it (remove whitespace at both ends)
        std::string ln;
        safeGetline(fAc, ln);
        trim(ln);
        
        // skip over empty lines
        if (ln.empty())
            continue;
        
        // We are only looking for EXPORT_NAME here
        std::vector<std::string> tokens = str_tokenize(ln, WHITESPACE);
        if (tokens.size() == 2 &&
            tokens[0] == "EXPORT_NAME")
        {
            // Found a package id -> save an entry for a package
            auto p = glob.mapCSLPkgs.insert(std::make_pair(tokens[1], path + XPLMGetDirectorySeparator()[0]));
            if (!p.second) {                // not inserted, ie. package name existed already?
                LOG_MSG(logWARN, WARN_DUP_PKG_NAME,
                        tokens[1].c_str(), StripXPSysDir(path).c_str(),
                        p.first->second.c_str());
            } else {
                LOG_MSG(logDEBUG, "Added package '%s' from %s",
                        tokens[1].c_str(), StripXPSysDir(path).c_str());
            }
        }
    }
    
    // Close the xsb_aircraft.txt file
    fAc.close();
    
    // Success
    return "";
}