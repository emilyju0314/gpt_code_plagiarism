unsigned *Helper::getIntegerScaledCIELabFromCIELab(float *cieLab, unsigned *cieLabScaled) {
    // per PS 3.3 C.10.7.1.1 ... scale same way as ICC profile encodes them
    cieLabScaled[0] = (int) floor(cieLab[0] * 65535. / 100. + .5);
    cieLabScaled[1] = (int) floor((cieLab[1] + 128) * 65535. / 255. + .5);
    cieLabScaled[2] = (int) floor((cieLab[2] + 128) * 65535. / 255. + .5);
    return cieLabScaled;
  }