void field::setCoreSlice() {
    cuBound = gridData.collocCoreDomain.ubound();

    if (xStag) {
        cuBound(0) = gridData.staggrCoreDomain.ubound()(0);
    }

    if (yStag) {
        cuBound(1) = gridData.staggrCoreDomain.ubound()(1);
    }

    if (zStag) {
        cuBound(2) = gridData.staggrCoreDomain.ubound()(2);
    }

    // Following lines taken from Aether to correct periodic BCs for channel flow - test it thoroughly
    // They need to be commented when using Method 3 in setBulkSlice function below
    // Pushing the last point at the end of the domain inside by one unit of grid spacing for periodic domains
    //if (xStag and gridData.xRank == gridData.npX - 1 and inputParams.xPer) cuBound(0) -= 1;
    //if (yStag and gridData.yRank == gridData.npY - 1 and inputParams.yPer) cuBound(1) -= 1;
    //if (zStag and inputParams.zPer) cuBound(2) -= 1;

    fCore = blitz::RectDomain<3>(blitz::TinyVector<int, 3>(0, 0, 0), cuBound);

    // As of Dec 2019, the below slices are used only in the divergence calculation of vfield and gradient calculation of sfield and plainsf
    fCLft = shift(0, fCore, -1);
    fCRgt = shift(0, fCore,  1);

    fCFrt = shift(1, fCore, -1);
    fCBak = shift(1, fCore,  1);

    fCBot = shift(2, fCore, -1);
    fCTop = shift(2, fCore,  1);
}