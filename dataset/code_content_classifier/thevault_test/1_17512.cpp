CSLModelInfo_t::CSLModelInfo_t(const CSLModel& csl) :
    cslId(csl.cslId), modelName(csl.modelName),
    xsbAircraftPath(csl.xsbAircraftPath), xsbAircraftLn(csl.xsbAircraftLn),
    icaoType(csl.GetIcaoType()),
    doc8643Classification(csl.GetDoc8643().classification),
    doc8643WTC(csl.GetDoc8643().wtc)
{
    // copy all match criteria
    for (const CSLModel::MatchCritTy& crit : csl.vecMatchCrit)
        vecMatchCrit.emplace_back(CSLModelInfo_t::MatchCrit_t{crit.icaoAirline, crit.livery});
}