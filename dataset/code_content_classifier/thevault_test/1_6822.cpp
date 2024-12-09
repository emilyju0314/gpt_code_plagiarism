void TBrateLimitor::setRate(double rate) {
  last_token_rate = token_rate;
  
  if (! token_rate) {
    token_rate = rate;
  } else if (rate != token_rate) {
    // use HLF to change token rate
    hlf.update(rate);
    // Use low-gain filter for fast response
    //token_rate = hlf.getLow();
    token_rate = hlf.getHigh();
    token_rate = rate;
  }
  
  printf("TR %d %.2f %.2f %d %d\n", (int)(Scheduler::instance().clock()), 
	 token_rate, rate, p_score, n_score);
}