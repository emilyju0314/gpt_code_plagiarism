void derivative::calcDerivative1_y(blitz::Array<real, 3> outputMat) {
    outputMat(fullRange, blitz::Range(0, F.F.ubound(1) - 1), fullRange) = central12n(F.F, 1);
    outputMat *= invDely;

    outputMat = y_Metric(j)*outputMat(i, j, k);
}