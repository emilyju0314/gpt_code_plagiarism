void derivative::calcDerivative1_x(blitz::Array<real, 3> outputMat) {
    outputMat(blitz::Range(0, F.F.ubound(0) - 1), fullRange, fullRange) = central12n(F.F, 0);
    outputMat *= invDelx;

    outputMat = x_Metric(i)*outputMat(i, j, k);
}