CSLModel* CSLModelByPkgShortId (std::uint16_t _pkgHash,
                                const std::string& _shortId)
{
    // try finding the model by shortId, also verify pckage hash
    mapCSLModelTy::iterator iBest = glob.mapCSLModels.end();
    for (mapCSLModelTy::iterator iter = glob.mapCSLModels.begin();
         iter != glob.mapCSLModels.end();
         ++iter)
    {
        // short id matches...as far as known
        if (std::strncmp(iter->second.GetShortId().c_str(), _shortId.c_str(), _shortId.length()) == 0) {
            if (iter->second.pkgHash == _pkgHash) {     // perfect match!
                iBest = iter;
                break;
            }
            else if (iBest == glob.mapCSLModels.end() &&// remember the first model for which at least the short id matches
                     !iter->second.IsObjInvalid())
                iBest = iter;                           // but keep on searching
        }
    }
    
    // not found, or invalid?
    if (iBest == glob.mapCSLModels.end() || iBest->second.IsObjInvalid())
        return nullptr;
    
    // Success
    return &iBest->second;
}