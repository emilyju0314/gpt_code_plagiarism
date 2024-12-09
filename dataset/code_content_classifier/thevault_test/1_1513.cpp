void ScatterPlotWindow::setMousePosition(MdiCubeViewport *vp,
                                           QPoint mouseLoc) {
    ScatterPlotData *scatterData =
        dynamic_cast<ScatterPlotData *>(m_spectrogram->data());

    if (scatterData) {
      scatterData->clearAlarms();

      if (alarmingPlot() && (isXCube(vp) || isYCube(vp))) {
        QScopedPointer<Portal> xCubePortal(
            new Portal(m_alarmPlotSamples, m_alarmPlotLines,
                       m_xAxisCube->pixelType()));
        QScopedPointer<Portal> yCubePortal(
            new Portal(m_alarmPlotSamples, m_alarmPlotLines,
                       m_yAxisCube->pixelType()));

        double cubeSample = Null;
        double cubeLine = Null;

        vp->viewportToCube(mouseLoc.x(), mouseLoc.y(), cubeSample, cubeLine);

        // The sample/line range is the actual scatter plotted sample/line
        //   range. Don't alarm outside of this range on the cube ever.
        if (cubeSample >= m_sampleRange.minValue() - 0.5 &&
            cubeSample <= m_sampleRange.maxValue() + 0.5 &&
            cubeLine >= m_lineRange.minValue() - 0.5 &&
            cubeLine <= m_lineRange.maxValue() + 0.5) {
          xCubePortal->SetPosition(cubeSample, cubeLine, m_xAxisCubeBand);
          m_xAxisCube->read(*xCubePortal);
          yCubePortal->SetPosition(cubeSample, cubeLine, m_yAxisCubeBand);
          m_yAxisCube->read(*yCubePortal);

          ASSERT(xCubePortal->size() == yCubePortal->size());
          for (int i = 0; i < xCubePortal->size(); i++) {
            double x = (*xCubePortal)[i];
            double y = (*yCubePortal)[i];

            if (!IsSpecial(x) && !IsSpecial(y)) {
              scatterData->alarm(x, y);
            }
          }
        }
      }

      plot()->replot();
    }
  }