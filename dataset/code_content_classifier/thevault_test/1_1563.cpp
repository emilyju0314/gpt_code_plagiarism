void SpectralPlotTool::validatePlotCurves() {
    PlotWindow *targetWindow = selectedWindow();

    if (targetWindow) {
      PlotCurve::Units targetUnits = (PlotCurve::Units)m_displayCombo->itemData(
            m_displayCombo->currentIndex()).toInt();

      QPen avgPen(Qt::white);
      avgPen.setWidth(1);
      avgPen.setStyle(Qt::SolidLine);

      QPen minMaxPen(Qt::cyan);
//       minMaxPen.setStyle(Qt::DashLine);
      minMaxPen.setWidth(1);
      minMaxPen.setStyle(Qt::SolidLine);

      QPen stdDevPen(Qt::red);
      stdDevPen.setWidth(1);
//       stdDevPen.setStyle(Qt::DotLine);
      stdDevPen.setStyle(Qt::SolidLine);

      QPen stdErrPen(Qt::green);
      stdErrPen.setWidth(1);
//       stdErrPen.setStyle(Qt::DotLine);
      stdErrPen.setStyle(Qt::SolidLine);

      foreach (MdiCubeViewport *viewport, viewportsToPlot()) {
        if (m_plotAvgAction->isChecked() &&
           (!(*m_avgCurves)[viewport] ||
            (*m_avgCurves)[viewport]->xUnits() != targetUnits)) {
          CubePlotCurve *plotCurve = createCurve("Average", avgPen,
              targetUnits, CubePlotCurve::CubeDN);
          m_avgCurves->insert(viewport, plotCurve);
          targetWindow->add(plotCurve);
        }

        if (m_plotMinAction->isChecked() &&
           (!(*m_minCurves)[viewport] ||
            (*m_minCurves)[viewport]->xUnits() != targetUnits)) {
          CubePlotCurve *plotCurve = createCurve("Minimum", minMaxPen,
              targetUnits, CubePlotCurve::CubeDN);
          m_minCurves->insert(viewport, plotCurve);
          targetWindow->add(plotCurve);
        }

        if (m_plotMaxAction->isChecked() &&
           (!(*m_maxCurves)[viewport] ||
            (*m_maxCurves)[viewport]->xUnits() != targetUnits)) {
          CubePlotCurve *plotCurve = createCurve("Maximum", minMaxPen,
              targetUnits, CubePlotCurve::CubeDN);
          m_maxCurves->insert(viewport, plotCurve);
          targetWindow->add(plotCurve);
        }

        if (m_plotStdDev1Action->isChecked() &&
           (!(*m_stdDev1Curves)[viewport] ||
            (*m_stdDev1Curves)[viewport]->xUnits() != targetUnits)) {
          CubePlotCurve *plotCurve = createCurve("+ Sigma", stdDevPen,
              targetUnits, CubePlotCurve::CubeDN);
          m_stdDev1Curves->insert(viewport, plotCurve);
          targetWindow->add(plotCurve);
        }

        if (m_plotStdDev2Action->isChecked() &&
           (!(*m_stdDev2Curves)[viewport] ||
            (*m_stdDev2Curves)[viewport]->xUnits() != targetUnits)) {
          CubePlotCurve *plotCurve = createCurve("- Sigma", stdDevPen,
              targetUnits, CubePlotCurve::CubeDN);
          m_stdDev2Curves->insert(viewport, plotCurve);
          targetWindow->add(plotCurve);
        }

        if (m_plotStdErr1Action->isChecked() &&
           (!(*m_stdErr1Curves)[viewport] ||
            (*m_stdErr1Curves)[viewport]->xUnits() != targetUnits)) {
          CubePlotCurve *plotCurve = createCurve("+ Std Error", stdErrPen,
              targetUnits, CubePlotCurve::CubeDN);
          m_stdErr1Curves->insert(viewport, plotCurve);
          targetWindow->add(plotCurve);
        }

        if (m_plotStdErr2Action->isChecked() &&
           (!(*m_stdErr2Curves)[viewport] ||
            (*m_stdErr2Curves)[viewport]->xUnits() != targetUnits)) {
          CubePlotCurve *plotCurve = createCurve("- Std Error", stdErrPen,
              targetUnits, CubePlotCurve::CubeDN);
          m_stdErr2Curves->insert(viewport, plotCurve);
          targetWindow->add(plotCurve);
        }
      }
    }
  }