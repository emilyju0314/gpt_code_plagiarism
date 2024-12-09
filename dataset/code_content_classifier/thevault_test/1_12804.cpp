void CSCCathodeLCTProcessor::setConfigParameters(const CSCDBL1TPParameters* conf)
{
  static std::atomic<bool> config_dumped{false};

  fifo_tbins   = conf->clctFifoTbins();
  fifo_pretrig = conf->clctFifoPretrig();
  hit_persist  = conf->clctHitPersist();
  drift_delay  = conf->clctDriftDelay();
  nplanes_hit_pretrig = conf->clctNplanesHitPretrig();
  nplanes_hit_pattern = conf->clctNplanesHitPattern();
  pid_thresh_pretrig = conf->clctPidThreshPretrig();
  min_separation     = conf->clctMinSeparation();

  // Check and print configuration parameters.
  checkConfigParameters();
  if (!config_dumped) {
    //std::cerr<<"**** CLCT setConfigParams parameters dump ****"<<std::endl;
    dumpConfigParams();
    config_dumped = true;
  }
}