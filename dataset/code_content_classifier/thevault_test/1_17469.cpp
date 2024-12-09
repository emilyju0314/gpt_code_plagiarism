void PlanesCycleModels ()
{
    // increase the index into our list of CSL models
    // (this is the index used by the first plane, the XPMP2::Aircraft one)
    gModelIdxBase = (gModelIdxBase + 1) % 3;

    // Now apply the new model to the 3 planes
    if (pSamplePlane)
        pSamplePlane->ChangeModel(PLANE_MODEL[gModelIdxBase][0],  // type
                                  PLANE_MODEL[gModelIdxBase][1],  // airline
                                  PLANE_MODEL[gModelIdxBase][2]); // livery
    if (pLegacyPlane)
        pLegacyPlane->ChangeModel(PLANE_MODEL[(gModelIdxBase+1)%3][0],  // type
                                  PLANE_MODEL[(gModelIdxBase+1)%3][1],  // airline
                                  PLANE_MODEL[(gModelIdxBase+1)%3][2]); // livery
    if (hStdPlane)
        XPMPChangePlaneModel(hStdPlane,
                             PLANE_MODEL[(gModelIdxBase+2)%3][0].c_str(),  // type
                             PLANE_MODEL[(gModelIdxBase+2)%3][1].c_str(),  // airline
                             PLANE_MODEL[(gModelIdxBase+2)%3][2].c_str()); // livery

    if (pSamplePlane) {
        // Demonstrate how to get detailed info of the model in use
        XPMP2::CSLModelInfo_t cslInfo = pSamplePlane->GetModelInfo();
        LogMsg("XPMP2-Sample: SamplePlane now using model %s of type %s as defined in line %d of %s",
            cslInfo.modelName.c_str(), cslInfo.icaoType.c_str(),
            cslInfo.xsbAircraftLn, cslInfo.xsbAircraftPath.c_str());
        for (const XPMP2::CSLModelInfo_t::MatchCrit_t& crit : cslInfo.vecMatchCrit)
            LogMsg("     Matches: %s | %s", crit.icaoAirline.c_str(), crit.livery.c_str());
    }

    // Completely unrelated...just for a change and for testing that functionality:
    // We also toggle the display of labels in the map:
    gbMapLabels = !gbMapLabels;
    XPMPEnableMap(true, gbMapLabels);
}