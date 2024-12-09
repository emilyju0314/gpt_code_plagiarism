void CSCAnodeLCTProcessor::setConfigParameters(const CSCDBL1TPParameters* conf)
{
  static std::atomic<bool> config_dumped{false};

  fifo_tbins   = conf->alctFifoTbins();
  fifo_pretrig = conf->alctFifoPretrig();
  drift_delay  = conf->alctDriftDelay();
  nplanes_hit_pretrig = conf->alctNplanesHitPretrig();
  nplanes_hit_pattern = conf->alctNplanesHitPattern();
  nplanes_hit_accel_pretrig = conf->alctNplanesHitAccelPretrig();
  nplanes_hit_accel_pattern = conf->alctNplanesHitAccelPattern();
  trig_mode        = conf->alctTrigMode();
  accel_mode       = conf->alctAccelMode();
  l1a_window_width = conf->alctL1aWindowWidth();

  // Check and print configuration parameters.
  checkConfigParameters();
  if (!config_dumped) {
    //std::cout<<"**** ALCT setConfigParam parameters dump ****"<<std::endl;
    dumpConfigParams();
    config_dumped = true;
  }
}