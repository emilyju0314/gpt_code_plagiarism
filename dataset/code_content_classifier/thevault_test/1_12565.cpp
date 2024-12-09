void derivative::calcDerivative2xx(blitz::Array<real, 3> outputMat) {
    tempMat(blitz::Range(0, F.F.ubound(0) - 1), fullRange, fullRange) = central12n(F.F, 0);
    tempMat *= invDelx;

    outputMat(blitz::Range(0, F.F.ubound(0) - 1), fullRange, fullRange) = central22n(F.F, 0);
    outputMat *= invDelx*invDelx;

    if (inputParams.iScheme == 1) {
        outputMat = xxMetric(i)*tempMat(i, j, k) + 0.5*x2Metric(i)*outputMat(i, j, k);
    } else {
        outputMat = xxMetric(i)*tempMat(i, j, k) + x2Metric(i)*outputMat(i, j, k);
    }
    
}