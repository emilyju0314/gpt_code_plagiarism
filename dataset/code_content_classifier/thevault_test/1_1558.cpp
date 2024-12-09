PlotWindow *SpectralPlotTool::createWindow() {
    PlotWindow *window = new SpectralPlotWindow(
        (PlotCurve::Units)m_displayCombo->itemData(
          m_displayCombo->currentIndex()).toInt(),
        qobject_cast<QWidget *>(parent()));
    window->setWindowTitle("Spectral " + PlotWindow::defaultWindowTitle());

    return window;
  }