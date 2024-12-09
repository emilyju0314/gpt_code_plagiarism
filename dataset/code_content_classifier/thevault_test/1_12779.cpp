std::vector<CSCCorrelatedLCTDigi> CSCMotherboard::getLCTs() const {
  std::vector<CSCCorrelatedLCTDigi> tmpV;

  bool me11 = (theStation == 1 &&
               CSCTriggerNumbering::ringFromTriggerLabels(theStation,
                                                          theTrigChamber)==1);

  // Do not report LCTs found in ME1/A if mpc_block_me1/a is set.
  for (int bx = 0; bx < CSCConstants::MAX_LCT_TBINS; bx++) {
    if (firstLCT[bx].isValid())
      if (!mpc_block_me1a || (!me11 || firstLCT[bx].getStrip() <= 127))
        tmpV.push_back(firstLCT[bx]);
    if (secondLCT[bx].isValid())
      if (!mpc_block_me1a || (!me11 || secondLCT[bx].getStrip() <= 127))
        tmpV.push_back(secondLCT[bx]);
  }
  return tmpV;
}