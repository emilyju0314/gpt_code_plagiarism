void field::setBulkSlice() {
    blitz::TinyVector<int, 3> blBound;
    blitz::TinyVector<int, 3> buBound;

    blBound = gridData.collocCoreDomain.lbound();
    buBound = gridData.collocCoreDomain.ubound();

    if (xStag) {
        blBound(0) = gridData.staggrCoreDomain.lbound()(0);
        buBound(0) = gridData.staggrCoreDomain.ubound()(0);
    }

    if (yStag) {
        blBound(1) = gridData.staggrCoreDomain.lbound()(1);
        buBound(1) = gridData.staggrCoreDomain.ubound()(1);
    }

    if (zStag) {
        blBound(2) = gridData.staggrCoreDomain.lbound()(2);
        buBound(2) = gridData.staggrCoreDomain.ubound()(2);
    }

    // Bulk and core slices are differentiated only in the boundary sub-domains,
    // and that differentiation is imposed in the following lines
    // At all interior sub-domains after performing MPI domain decomposition,
    // the bulk and core slices are identical

    // Different ways of defining bulk are clubbed together
    // The correct method needs to be chosen through Swayamvar

    // Method 1: The method originally present in Saras
    /*
    if (xStag and gridData.xRank == 0) blBound(0) += 1;

    if (xStag and gridData.xRank == gridData.npX - 1) buBound(0) -= 1;

    if (yStag and gridData.yRank == 0) blBound(1) += 1;

    if (yStag and gridData.yRank == gridData.npY - 1) buBound(1) -= 1;

    if (zStag) {
        blBound(2) += 1;
        buBound(2) -= 1;
    }
    */

    // Method 2: The method implemented after long discussions - shift the entire bulk to one side
    /*
    if (xStag and gridData.xRank == 0 and not inputParams.xPer) blBound(0) += 1;

    if (xStag and gridData.xRank == gridData.npX - 1) {
        inputParams.xPer? buBound(0) -= 2: buBound(0) -= 1;
    }

    if (yStag and gridData.yRank == 0 and not inputParams.yPer) blBound(1) += 1;

    if (yStag and gridData.yRank == gridData.npY - 1) {
        inputParams.yPer? buBound(1) -= 2: buBound(1) -= 1;
    }

    if (zStag) {
        if (not inputParams.zPer) {
            blBound(2) += 1;
            buBound(2) -= 1;
        } else {
            buBound(2) -= 2;
        }
    }
    */

    // Method 3: Seemingly the oldest version that existed in Aether
    if (xStag and gridData.xRank == 0 and not inputParams.xPer) blBound(0) += 1;

    if (xStag and gridData.xRank == gridData.npX - 1 and not inputParams.xPer) buBound(0) -= 1;
    
    if (yStag and gridData.yRank == 0 and not inputParams.yPer) blBound(1) += 1;

    if (yStag and gridData.yRank == gridData.npY - 1 and not inputParams.yPer) buBound(1) -= 1;

    if (zStag) {
        if (not inputParams.zPer) {
            blBound(2) += 1;
            buBound(2) -= 1;
        }
    }

#ifdef PLANAR
    blBound(1) = 0;
    buBound(1) = 0;
#endif

    fBulk = blitz::RectDomain<3>(blBound, buBound);
}