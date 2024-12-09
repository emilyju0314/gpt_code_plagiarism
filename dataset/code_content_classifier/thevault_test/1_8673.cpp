float *Helper::getCIELabFromIntegerScaledCIELab(unsigned *cieLabScaled, float *cieLab) {
    cieLab[0] = (float) (((double) cieLabScaled[0]) / 65535 * 100);
    cieLab[1] = (float) (((double) cieLabScaled[1]) / 65535 * 255 - 128);
    cieLab[2] = (float) (((double) cieLabScaled[2]) / 65535 * 255 - 128);
    return cieLab;
  }