void derivative::calcDerivative2zz(blitz::Array<real, 3> outputMat) {
    tempMat(fullRange, fullRange, blitz::Range(0, F.F.ubound(2) - 1)) = central12n(F.F, 2);
    tempMat *= invDelz;

    outputMat(fullRange, fullRange, blitz::Range(0, F.F.ubound(2) - 1)) = central22n(F.F, 2);
    outputMat *= invDelz*invDelz;
    
    if (inputParams.iScheme == 1) {
        outputMat = zzMetric(k)*tempMat(i, j, k) + 0.5*z2Metric(k)*outputMat(i, j, k);
    } else {
        outputMat = zzMetric(k)*tempMat(i, j, k) + z2Metric(k)*outputMat(i, j, k);
    }
}