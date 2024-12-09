void PlotWindow::updateVisibility(PlotCurve *curve) {
    if (m_showHideAllCurves) {
      if (m_showHideAllCurves->text() == "Hide All Curves") {
        curve->show();
      }
      else {
        curve->hide();
      }

      if (m_showHideAllMarkers->text() == "Hide All Symbols") {
        curve->setMarkerVisible(true);
      }
      else {
        curve->setMarkerVisible(false);
      }
    }

    emit plotChanged();
  }