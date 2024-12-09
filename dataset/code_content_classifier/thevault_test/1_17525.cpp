void CSLModelsAdd (CSLModel& _csl)
{
    // the main map, which actually "owns" the object, indexed by key
    const std::string cslKey = _csl.GetKeyString();
    auto p = glob.mapCSLModels.emplace(cslKey, std::move(_csl));
    if (!p.second) {                    // not inserted, ie. not a new entry!
        LOG_MSG(logWARN, WARN_DUP_MODEL, p.first->second.GetModelName().c_str(),
                p.first->second.xsbAircraftLn,
                StripXPSysDir(p.first->second.xsbAircraftPath).c_str());
    } else {
        // Need to update the cslKey that is stored in the CSL objects as only now we have the final value
        for (CSLObj& obj : p.first->second.listObj)
            obj.cslKey = cslKey;
    }

    // in all cases properly reset the passed-in reference
    _csl = CSLModel();
}