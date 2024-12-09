void derivative::calcDerivative2yy(blitz::Array<real, 3> outputMat) {
    tempMat(fullRange, blitz::Range(0, F.F.ubound(1) - 1), fullRange) = central12n(F.F, 1);
    tempMat *= invDely;

    outputMat(fullRange, blitz::Range(0, F.F.ubound(1) - 1), fullRange) = central22n(F.F, 1);
    outputMat *= invDely*invDely;
    
    if (inputParams.iScheme == 1) {
        outputMat = yyMetric(j)*tempMat(i, j, k) + 0.5*y2Metric(j)*outputMat(i, j, k);
    } else {
        outputMat = yyMetric(j)*tempMat(i, j, k) + y2Metric(j)*outputMat(i, j, k);
    }
}