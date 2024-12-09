void quantize_fp_nz_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs,
                      int skip_block, const int16_t *round_ptr,
                      const int16_t *quant_ptr, tran_low_t *qcoeff_ptr,
                      tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr,
                      uint16_t *eob_ptr, const int16_t *scan,
                      const int16_t *iscan) {
  int i, eob = -1;
  const int thr = dequant_ptr[1] >> 1;
  (void)iscan;
  (void)skip_block;
  assert(!skip_block);

  // Quantization pass: All coefficients with index >= zero_flag are
  // skippable. Note: zero_flag can be zero.
  for (i = 0; i < n_coeffs; i += 16) {
    int y;
    int nzflag_cnt = 0;
    int abs_coeff[16];
    int coeff_sign[16];

    // count nzflag for each row (16 tran_low_t)
    for (y = 0; y < 16; ++y) {
      const int rc = i + y;
      const int coeff = coeff_ptr[rc];
      coeff_sign[y] = (coeff >> 31);
      abs_coeff[y] = (coeff ^ coeff_sign[y]) - coeff_sign[y];
      // The first 16 are skipped in the sse2 code.  Do the same here to match.
      if (i >= 16 && (abs_coeff[y] <= thr)) {
        nzflag_cnt++;
      }
    }

    for (y = 0; y < 16; ++y) {
      const int rc = i + y;
      // If all of the AC coeffs in a row has magnitude less than the
      // quantization step_size/2, quantize to zero.
      if (nzflag_cnt < 16) {
        int tmp =
            clamp(abs_coeff[y] + round_ptr[rc != 0], INT16_MIN, INT16_MAX);
        tmp = (tmp * quant_ptr[rc != 0]) >> 16;
        qcoeff_ptr[rc] = (tmp ^ coeff_sign[y]) - coeff_sign[y];
        dqcoeff_ptr[rc] = qcoeff_ptr[rc] * dequant_ptr[rc != 0];
      } else {
        qcoeff_ptr[rc] = 0;
        dqcoeff_ptr[rc] = 0;
      }
    }
  }

  // Scan for eob.
  for (i = 0; i < n_coeffs; i++) {
    // Use the scan order to find the correct eob.
    const int rc = scan[i];
    if (qcoeff_ptr[rc]) {
      eob = i;
    }
  }
  *eob_ptr = eob + 1;
}