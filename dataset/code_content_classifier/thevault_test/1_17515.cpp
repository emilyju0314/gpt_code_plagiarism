float CSLObj::FetchVertOfsFromObjFile () const
{
    float min = 0.0f, max = 0.0f;
    
    // Which file to read? Use pathOrig if defined because it could be that path doesn't exist yet
    const std::string& _path = pathOrig.empty() ? path : pathOrig;
    
    // Try opening our `.obj` file...that should actually work,
    // CSLObj only exists if the `.obj` file exists,
    // so we deal with errors but don't issue a lot of warnings here
    int lnNr = 0;
    std::ifstream fIn (TOPOSIX(_path));
    if (!fIn.good()) {
        LOG_MSG(logERR, ERR_COULD_NOT_OPEN, StripXPSysDir(_path).c_str());
        return 0.0f;
    }
    while (fIn)
    {
        std::string ln;
        safeGetline(fIn, ln);
        lnNr++;
        
        // line number 2 must define the version
        if (lnNr == 2) {
            // we can only read OBJ8 files
            if (std::stol(ln) < 800) {
                LOG_MSG(logWARN, WARN_OBJ8_ONLY_VERTOFS,
                        ln.c_str(), StripXPSysDir(_path).c_str());
                return 0.0f;
            }
        }
        
        // We try to decide really fast...obj files can be long
        // We are looking for "VT" and "VLINE", each will have at least 20 chars
        // and the first one must be 'V', the 2nd one either T or L
        if (ln.size() < 20 || ln[0] != 'V' ||
            (ln[1] != 'T' && ln[1] != 'L'))
            continue;
        
        // Chances are good we process it, so let's break it up into tokens
        std::vector<std::string> tokens = str_tokenize(ln, " \t");
        if (tokens.size() < 7 ||            // VT/VLINE must have 7 elements
            (tokens[0] != "VT" && tokens[0] != "VLINE"))
            continue;
        
        // Get and process the Y coordinate
        const float y = std::stof(tokens[2]);
        if (y < min)
            min = y;
        else if (y > max)
            max = y;
    }
    
    // return the proper VERT_OFFSET based on the Y coordinates we have read
    const float vertOfs = min < 0.0f ? -min : -max;
    LOG_MSG(logDEBUG, "Fetched VERT_OFFSET=%.1f from %s", vertOfs, StripXPSysDir(_path).c_str());
    return vertOfs;
}