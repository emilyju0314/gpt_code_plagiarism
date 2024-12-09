const char* CSLModelsProcessAcFile (const std::string& path)
{
    // for a good but concise message about ignored elements we keep this list
    std::map<std::string, int> ignoredCmd;
    // for a good but concise message about read a/c we keep this map, keyed by ICAO type designator
    std::map<std::string, int> acRead;
    // for a good but concise message about ignored OBJECTs and AIRCRAFT we keep this list
    std::map<std::string, int> ignoredObj;

    // The package's name
    std::string exportName = "?";
    
    // Here we collect the next CSL model
    CSLModel csl;
    
    // Open the xsb_aircraft.txt file
    const std::string xsbName (path + XPLMGetDirectorySeparator()[0] + XSB_AIRCRAFT_TXT);
    std::ifstream fAc (TOPOSIX(xsbName));
    if (!fAc || !fAc.is_open())
        return WARN_NO_XSBACTXT_FOUND;
    
    // read the file line by line
    LOG_MSG(logDEBUG, DEBUG_XSBACTXT_READ, StripXPSysDir(xsbName).c_str());
    for (int lnNr = 1; fAc; ++lnNr)
    {
        // read a line, trim it (remove whitespace at both ends)
        std::string ln;
        safeGetline(fAc, ln);
        trim(ln);
        
        // skip over empty lines or lines starting a comment
        if (ln.empty() || ln[0] == '#')
            continue;
        
        // Break up the line into individual parameters and work on its commands
        std::vector<std::string> tokens = str_tokenize(ln, WHITESPACE);
        if (tokens.empty()) continue;
        
        // DEPENDENCY: We warn if we don't find the package but try anyway
        if (tokens[0] == "DEPENDENCY")
            AcTxtLine_DEPENDENCY(tokens, lnNr);
        
        // EXPORT_NAME: Already processed, but needed for model id
        else if (tokens[0] == "EXPORT_NAME") {
            exportName = ln.substr(12);
            trim(exportName);
        }

        // OBJECT or AIRCRAFT aren't supported any longer, but as they are supposed start
        // another aircraft we need to make sure to save the one defined previously,
        // and we use the chance to issue some warnings into the log
        else if (tokens[0] == "OBJECT" || tokens[0] == "AIRCRAFT") {
            AcTxtLine_OBJECT_AIRCRAFT(csl, ln, lnNr);
            if (tokens.size() >= 2)
                ignoredObj[tokens[1]]++;
            else
                ignoredObj["<unknown>"]++;
        }

        // OBJ8_AIRCRAFT: Start a new aircraft specification
        else if (tokens[0] == "OBJ8_AIRCRAFT") {
            if (csl.IsValid()) acRead[csl.GetIcaoType()]++;
            AcTxtLine_OBJ8_AIRCRAFT(csl, ln, path, exportName, lnNr);
            continue;                   // don't run into the "ignored" counter later
        }
        
        // -- All following commands only make sense if a model has previously
        //    been started with OBJ8_AIRCRAFT, which sets the csl's id ---
        if (csl.GetId().empty())
            continue;                   // skip the line if no model defined
        
        // OBJ8: Define the object file to load
        if (tokens[0] == "OBJ8")
            AcTxtLine_OBJ8(csl, tokens, lnNr);

        // VERT_OFFSET: Defines the vertical offset of the model, so the wheels correctly touch the ground
        else if (tokens[0] == "VERT_OFFSET")
            AcTxtLine_VERT_OFFSET(csl, tokens, lnNr);
        
        // OFFSET: 3rd parameter defines the vertical offset of the model, so the wheels correctly touch the ground
        else if (tokens[0] == "OFFSET")
            AcTxtLine_OFFSET(csl, tokens, lnNr);
        
        // The matching parameters will be processed the same way...
        else if (tokens[0] == "ICAO" ||
                 tokens[0] == "AIRLINE" ||
                 tokens[0] == "LIVERY" ||
                 tokens[0] == "MATCHES")
            AcTxtLine_MATCHES(csl, tokens, lnNr);

        // else...we just ignore it but count the commands for a proper warning later
        else
            ignoredCmd[tokens[0]]++;
    }
    
    // Close the xsb_aircraft.txt file
    fAc.close();
    
    // Don't forget to also save the last object
    if (csl.IsValid()) {
        acRead[csl.GetIcaoType()]++;
        CSLModelsAdd(csl);
    }
    
    // Log a message about the a/c we've read
    if (!acRead.empty()) {
        std::string acList;
        int totAcRead = StrCntString(acRead, acList);
        LOG_MSG(logINFO, INFO_XSBACTXT_DONE, totAcRead, acList.c_str(),
                StripXPSysDir(xsbName).c_str());
    }
    
    // Log a message about the a/c we've ignored
    if (!ignoredObj.empty()) {
        std::string acList;
        int totAcRead = StrCntString(ignoredObj, acList);
        LOG_MSG(logWARN, WARN_XSBACTXT_IGNORED, totAcRead, acList.c_str(),
                StripXPSysDir(xsbName).c_str());
    }
    
    // If there were ignored commands we list them once now
    if (!ignoredCmd.empty() && glob.bLogMdlMatch) {
        std::string msg(WARN_IGNORED_COMMANDS);
        char buf[25];
        for (const auto& i: ignoredCmd) {
            snprintf(buf, sizeof(buf), "%s (%dx), ",
                     i.first.c_str(), i.second);
            msg += buf;
        }
        msg.pop_back();                 // remove the last trailing ", "
        msg.pop_back();
        LOG_MSG(logWARN, "%s", msg.c_str());
    }

    // Success
    return "";
}