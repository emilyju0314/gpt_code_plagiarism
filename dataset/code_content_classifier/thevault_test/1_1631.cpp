void MosaicGridTool::setLonInc(Angle lonInc) {
    Angle lonRange = m_maxLon - m_minLon;

    if (lonInc > lonRange)
      m_lonInc = lonRange;
    else if (lonInc > Angle(0.0, Angle::Degrees))
      m_lonInc = lonInc;
  }