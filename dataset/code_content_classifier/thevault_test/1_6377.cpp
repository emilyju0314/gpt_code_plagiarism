double compute_prob(const bam1_t *rec)
{
  // According to rsem-calculate-expression -?, ``The MAPQ field of each
  // alignment is set to min(100, floor(-10 * log10(1.0 - w) + 0.5)), where w
  // is the posterior probability of that alignment being the true mapping of
  // a read.''
  //
  // To go backwards, we solve:
  //        min(100, floor(-10 * log10(1.0 - w) + 0.5) = q
  // i.e.,           round(-10 * log10(1.0 - w))       = q
  // i.e.,                 -10 * log10(1.0 - w)        = q
  // i.e.,                       log10(1.0 - w)        = -q/10
  // i.e.,                             1.0 - w         = 10^(-q/10)
  // i.e.,                                 - w         = 10^(-q/10) - 1.0
  // i.e.,                                   w         = -( 10^(-q/10) - 1.0 )
  //
  // As a doublecheck: In sam_rsem_cvt.h, there is the following function:
  //
  //   uint8_t getMAPQ(double val) {
  //       double err = 1.0 - val;
  //       if (err <= 1e-10) return 100;
  //       return (uint8_t)(-10 * log10(err) + .5); // round it
  //   }
  //
  // If we plug in val = -(10^(-q/10) - 1.0), we get
  //
  //    -10 * log10(err)
  // =  -10 * log10(1.0 - val)
  // =  -10 * log10(1.0 - (-(10^(-q/10) - 1.0)))
  // =  -10 * log10(1.0 + 10^(-q/10) - 1.0)
  // =  -10 * log10(      10^(-q/10)      )
  // =  -10 * (               -q/10       )
  // =  -     (               -q          )
  // =                         q           
  //
  // as expected if the above is correct.
  double prob = -(pow(10.0, -rec->core.qual/10.0) - 1.0);
  if (prob < 0.0 || prob > 1.0)
    throw std::runtime_error("Posterior probability of an alignment is < 0 or > 1.");
  return prob;
}