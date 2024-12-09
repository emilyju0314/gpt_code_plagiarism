bool PlotWindow::eventFilter(QObject *o, QEvent *e) {
    bool blockWidgetFromEvent = false;

    switch (e->type()) {
      case QEvent::MouseButtonPress:
        if (o == this &&
            childAt(((QMouseEvent *)e)->pos()) != plot()->canvas()) {
          mousePressEvent(o, (QMouseEvent *)e);
          blockWidgetFromEvent = true;
        }
        break;

      default:
        break;
    }

    bool stopHandlingEvent = false;
    if (!blockWidgetFromEvent && o == this) {
      stopHandlingEvent = MainWindow::eventFilter(o, e);

      if (e->type() == QEvent::Close && !stopHandlingEvent) {
        emit closed();
      }
    }

    return stopHandlingEvent || blockWidgetFromEvent;
  }