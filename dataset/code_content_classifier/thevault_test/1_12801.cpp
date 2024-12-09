std::vector<CSCALCTDigi> CSCAnodeLCTProcessor::getALCTs() {
  std::vector<CSCALCTDigi> tmpV;
  for (int bx = 0; bx < CSCConstants::MAX_ALCT_TBINS; bx++) {
    if (bestALCT[bx].isValid())   tmpV.push_back(bestALCT[bx]);
    if (secondALCT[bx].isValid()) tmpV.push_back(secondALCT[bx]);
  }
  return tmpV;
}