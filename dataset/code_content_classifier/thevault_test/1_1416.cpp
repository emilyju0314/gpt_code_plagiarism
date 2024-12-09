TRasterP TCleanupper::processColors(const TRasterP &rin) {
  if (m_parameters->m_lineProcessingMode == lpNone) return rin;

  TRasterCM32P rcm = TRasterCM32P(rin->getSize());
  if (!rcm) {
    assert(!"failed finalRas allocation!");
    return TRasterCM32P();
  }

  // Copy current cleanup palette to parameters' colors
  m_parameters->m_colors.update(m_parameters->m_cleanupPalette.getPointer(),
                                m_parameters->m_noAntialias);

  bool toGr8 = (m_parameters->m_lineProcessingMode == lpGrey);
  if (toGr8) {
    // No (color) processing. Not even thresholding. This just means that all
    // the important
    // stuff here is made in the brightness/contrast stage...

    // NOTE: Most of the color processing should be DISABLED in this case!!

    // finalRas->clear();
    rin->lock();
    rcm->lock();

    if (TRasterGR8P(rin)) {
      UCHAR *rowin    = rin->getRawData();
      TUINT32 *rowout = reinterpret_cast<TUINT32 *>(rcm->getRawData());
      for (int i = 0; i < rin->getLy(); i++) {
        for (int j = 0; j < rin->getLx(); j++)
          *rowout++ = *rowin++;  // Direct copy for now... :(
        rowin += rin->getWrap() - rin->getLx();
        rowout += rcm->getWrap() - rcm->getLx();
      }
    } else {
      TPixel32 *rowin = reinterpret_cast<TPixel32 *>(rin->getRawData());
      TUINT32 *rowout = reinterpret_cast<TUINT32 *>(rcm->getRawData());
      for (int i = 0; i < rin->getLy(); i++) {
        for (int j = 0; j < rin->getLx(); j++)
          *rowout++ = TPixelGR8::from(*rowin++).value;
        rowin += rin->getWrap() - rin->getLx();
        rowout += rcm->getWrap() - rcm->getLx();
      }
    }

    rin->unlock();
    rcm->unlock();
  } else {
    assert(TRaster32P(rin));
    preprocessColors(rcm, rin, m_parameters->m_colors);
  }

  // outImg->setDpi(outDpi.x, outDpi.y);
  CleanupPreprocessedImage cpi(m_parameters,
                               TToonzImageP(rcm, rcm->getBounds()), toGr8);
  cpi.m_autocentered = true;

  TRaster32P rout = TRaster32P(rin->getSize());
  finalize(rout, &cpi);
  return rout;
}