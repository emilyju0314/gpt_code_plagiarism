void CSCCathodeLCTProcessor::dumpDigis(const std::vector<int> strip[CSCConstants::NUM_LAYERS][CSCConstants::NUM_HALF_STRIPS_7CFEBS], const int stripType, const int nStrips) const
{
  LogDebug("CSCCathodeLCTProcessor")
    << CSCDetId::chamberName(theEndcap, theStation, theRing, theChamber)
    << " strip type " << stripType << " nStrips " << nStrips;

  std::ostringstream strstrm;
  for (int i_strip = 0; i_strip < nStrips; i_strip++) {
    if (i_strip%10 == 0) {
      if (i_strip < 100) strstrm << i_strip/10;
      else               strstrm << (i_strip-100)/10;
    }
    else                 strstrm << " ";
    if ((i_strip+1)%cfeb_strips[stripType] == 0) strstrm << " ";
  }
  strstrm << "\n";
  for (int i_strip = 0; i_strip < nStrips; i_strip++) {
    strstrm << i_strip%10;
    if ((i_strip+1)%cfeb_strips[stripType] == 0) strstrm << " ";
  }
  for (int i_layer = 0; i_layer < CSCConstants::NUM_LAYERS; i_layer++) {
    strstrm << "\n";
    for (int i_strip = 0; i_strip < nStrips; i_strip++) {
      if (!strip[i_layer][i_strip].empty()) {
	std::vector<int> bx_times = strip[i_layer][i_strip];
	// Dump only the first in time.
	strstrm << std::hex << bx_times[0] << std::dec;
      }
      else {
	strstrm << "-";
      }
      if ((i_strip+1)%cfeb_strips[stripType] == 0) strstrm << " ";
    }
  }
  LogTrace("CSCCathodeLCTProcessor") << strstrm.str();
}