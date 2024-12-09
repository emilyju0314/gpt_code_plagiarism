void PlotWindow::dragEnterEvent(QDragEnterEvent *event) {
    QObject *source = event->source();

    if (source != m_legend->contentsWidget() &&
        userCanAddCurve(event->mimeData())) {
      event->acceptProposedAction();
    }
  }