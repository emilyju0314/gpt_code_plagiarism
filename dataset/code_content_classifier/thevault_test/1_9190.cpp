dvector tcsam::convertToStdDev(dvector sclVal, dvector mnVal, int sclFlg){
    dvector sdv = 0.0*sclVal;
    if (sclFlg==SCLTYPE_CV) {
        sdv = elem_prod(sclVal,mnVal);
    } else if (sclFlg==SCLTYPE_STD) {
        sdv = sclVal;
    } else if (sclFlg==SCLTYPE_VAR) {
        sdv = sqrt(sclVal);
    }
    return sdv;
}