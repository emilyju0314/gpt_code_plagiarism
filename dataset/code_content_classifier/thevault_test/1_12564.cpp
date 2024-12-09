void derivative::calcDerivative1_z(blitz::Array<real, 3> outputMat) {
    outputMat(fullRange, fullRange, blitz::Range(0, F.F.ubound(2) - 1)) = central12n(F.F, 2);
    outputMat *= invDelz;

    outputMat = z_Metric(k)*outputMat(i, j, k);
}