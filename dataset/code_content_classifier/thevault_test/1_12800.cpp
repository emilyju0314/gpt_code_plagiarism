std::vector<CSCALCTDigi> CSCAnodeLCTProcessor::readoutALCTs() {
  std::vector<CSCALCTDigi> tmpV;

  // The number of LCT bins in the read-out is given by the
  // l1a_window_width parameter, but made even by setting the LSB of
  // l1a_window_width to 0.
  const int lct_bins =
    //    (l1a_window_width%2 == 0) ? l1a_window_width : l1a_window_width-1;
    l1a_window_width;
  static std::atomic<int> late_tbins{early_tbins + lct_bins};

  static std::atomic<int> ifois{0};
  if (ifois == 0) {

    //std::cout<<"ALCT early_tbins="<<early_tbins<<"  lct_bins="<<lct_bins<<"  l1a_window_width="<<l1a_window_width<<"  late_tbins="<<late_tbins<<std::endl;
    //std::cout<<"**** ALCT readoutALCTs config dump ****"<<std::endl;
    //dumpConfigParams();

    if (infoV >= 0 && early_tbins < 0) {
      edm::LogWarning("L1CSCTPEmulatorSuspiciousParameters")
        << "+++ fifo_pretrig = " << fifo_pretrig
        << "; in-time ALCTs are not getting read-out!!! +++" << "\n";
    }

    if (late_tbins > CSCConstants::MAX_ALCT_TBINS-1) {
      if (infoV >= 0) edm::LogWarning("L1CSCTPEmulatorSuspiciousParameters")
        << "+++ Allowed range of time bins, [0-" << late_tbins
        << "] exceeds max allowed, " << CSCConstants::MAX_ALCT_TBINS-1 << " +++\n"
        << "+++ Set late_tbins to max allowed +++\n";
      late_tbins = CSCConstants::MAX_ALCT_TBINS-1;
    }
    ifois = 1;
  }

  // Start from the vector of all found ALCTs and select those within
  // the ALCT*L1A coincidence window.
  std::vector<CSCALCTDigi> all_alcts = getALCTs();
  for (std::vector <CSCALCTDigi>::const_iterator plct = all_alcts.begin();
       plct != all_alcts.end(); plct++) {
    if (!plct->isValid()) continue;

    int bx = (*plct).getBX();
    // Skip ALCTs found too early relative to L1Accept.
    if (bx <= early_tbins) {
      if (infoV > 1) LogDebug("CSCAnodeLCTProcessor")
        << " Do not report ALCT on keywire " << plct->getKeyWG()
        << ": found at bx " << bx << ", whereas the earliest allowed bx is "
        << early_tbins+1;
      continue;
    }

    // Skip ALCTs found too late relative to L1Accept.
    if (bx > late_tbins) {
      if (infoV > 1) LogDebug("CSCAnodeLCTProcessor")
        << " Do not report ALCT on keywire " << plct->getKeyWG()
        << ": found at bx " << bx << ", whereas the latest allowed bx is "
        << late_tbins;
      continue;
    }

    tmpV.push_back(*plct);
  }

  // shift the BX from 8 to 3
  // ALCTs in real data have the central BX in bin 3
  // which is the middle of the 7BX wide L1A window
  // ALCTs used in the TMB emulator have central BX at bin 8
  // but right before we put emulated ALCTs in the event, we shift the BX
  // by -5 to make sure they are compatible with real data ALCTs!
  for (auto& p : tmpV){
    p.setBX(p.getBX() - (CSCConstants::LCT_CENTRAL_BX - l1a_window_width/2));
  }
  return tmpV;
}