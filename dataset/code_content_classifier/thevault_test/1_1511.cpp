bool ScatterPlotWindow::eventFilter(QObject *o, QEvent *e) {
    if (o == plot()->canvas()) {
      switch (e->type()) {
        case QEvent::MouseMove: {
          if (((QMouseEvent *)e)->buttons() == Qt::NoButton)
            mouseMoveEvent((QMouseEvent *)e);
          break;
        }
        case QEvent::Leave: {
          mouseLeaveEvent((QMouseEvent *)e);
          break;
        }
        default:
          break;
      }

      return false;
    }
    else {
      return PlotWindow::eventFilter(o, e);
    }
  }