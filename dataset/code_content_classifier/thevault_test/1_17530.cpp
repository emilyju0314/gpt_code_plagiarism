void AcTxtLine_OBJ8 (CSLModel& csl,
                     std::vector<std::string>& tokens,
                     int lnNr)
{
    if (tokens.size() >= 4) {
        // translate the path (replace the package with the full path)
        std::string path = CSLModelsConvPackagePath(tokens[3], lnNr);
        if (!path.empty()) {
            // save the path as an additional object to the model
            // (Paths  to .obj are always stored in POSIX format)
            csl.listObj.emplace_back(csl.GetKeyString(), TOPOSIX(path));
            CSLObj& obj = csl.listObj.back();

            // we can already read the TEXTURE and TEXTURE_LIT paths
            if (tokens.size() >= 5) {
                obj.texture = CSLModelsConvPackagePath(tokens[4], lnNr, true);
                if (tokens.size() >= 6)
                    obj.text_lit = CSLModelsConvPackagePath(tokens[5], lnNr, true);
            } // TEXTURE available
            
            // Determine which file to load and if we need a copied .obj file
            obj.DetermineWhichObjToLoad ();
        } // Package name valid
    } // at least 3 params
    else
        LOG_MSG(logERR, ERR_TOO_FEW_PARAM, lnNr, tokens[0].c_str(), 3);
}