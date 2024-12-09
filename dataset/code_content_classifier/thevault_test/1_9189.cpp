double tcsam::convertToStdDev(double sclVal, double mnVal, int sclFlg){
    double sdv = 0.0;
    if (sclFlg==SCLTYPE_CV) {
        sdv = sclVal*mnVal;
    } else if (sclFlg==SCLTYPE_STD) {
        sdv = sclVal;
    } else if (sclFlg==SCLTYPE_VAR) {
        sdv = sqrt(sclVal);
    }
    return sdv;
}