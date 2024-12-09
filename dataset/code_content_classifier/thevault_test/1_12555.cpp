field::field(const grid &gridData, std::string fieldName, const bool xStag, const bool yStag, const bool zStag):
             gridData(gridData),
             rankData(inputParams),
             xStag(xStag), yStag(yStag), zStag(zStag)
{
    this->fieldName = fieldName;

    fSize = gridData.collocFullSize;
    flBound = gridData.collocFullDomain.lbound();

    if (xStag) {
        fSize(0) = gridData.staggrFullSize(0);
        flBound(0) = gridData.staggrFullDomain.lbound()(0);
    }    

    if (yStag) {
        fSize(1) = gridData.staggrFullSize(1);
        flBound(1) = gridData.staggrFullDomain.lbound()(1);
     }

    if (zStag) {
        fSize(2) = gridData.staggrFullSize(2);
        flBound(2) = gridData.staggrFullDomain.lbound()(2);
    }

    F.resize(fSize);
    
    F.reindexSelf(flBound);

    mpiHandle = new mpidata(F, rankData);

    setCoreSlice();
          
    setBulkSlice();

    setWallSlices();

    setInterpolationSlices();

    mpiHandle->createSubarrays(fSize, cuBound + 1, gridData.padWidths, xStag, yStag);

    F = 0.0;
}