void MosaicGridTool::setLatInc(Angle latInc) {
    if (latInc > Angle(0.0, Angle::Degrees)) {
      m_latInc = latInc;
    }
  }