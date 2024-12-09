void CSLModel::AddMatchCriteria (const std::string& _type,
                                 const MatchCritTy& _matchCrit,
                                 int lnNr)
{
    // We cannot overwrite with a _different_ a/c ICAO type!
    if (!icaoType.empty() &&            // already defined
        icaoType != _type)              // but wanted something different now?
    {
        LOG_MSG(logWARN, WARN_DIFF_TYPE, lnNr,
                _type.c_str(), icaoType.c_str(), 
                modelName.c_str());
    }
    // set the ICAO aircraft type once and forever
    else if (icaoType.empty()) {
        icaoType = _type;
        doc8643 = & Doc8643Get(_type);
        related = RelatedGet(_type);
    }
    
    // See if we need to add the other match criterion
    // We try to keep as few and as specific match criteria as possible
    for (MatchCritTy& mc: vecMatchCrit)
        // can we merge the new with existing criteria?
        if (mc.merge(_matchCrit))
            return;

    // not merged: then add
    vecMatchCrit.push_back(_matchCrit);
}