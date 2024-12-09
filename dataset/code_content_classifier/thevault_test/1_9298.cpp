void ChelaHeightData::calcSizeBinIndices(const dvector& zCs){
    rpt::echo<<"Starting ChelaHeightData::calcSizeBinIndices(zCs)"<<endl;
    obsSizeBinIndex_n = wts::assignBinIndices(obsSize_n,zCs,0,0);
    rpt::echo<<"zCs = "<<zCs<<endl;
    for (int n=1;n<=nObs;n++) rpt::echo<<obsSize_n(n)<<tb<<obsSizeBinIndex_n(n)<<tb<<zCs(obsSizeBinIndex_n(n))<<endl;
    rpt::echo<<"Finished ChelaHeightData::calcSizeBinIndices(zCs)"<<endl;
}