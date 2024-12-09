FIR::FIR(int taps, double coefficients[]){
    num_taps = taps;
    current = 0;
    buffer.reserve(taps);
    buffer.assign(taps,0);
    coeff.reserve(taps);
    coeff.insert(coeff.begin(), coefficients, coefficients + taps);
}