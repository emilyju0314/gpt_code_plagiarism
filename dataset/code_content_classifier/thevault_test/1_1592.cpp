void PlotWindow::mousePressEvent(QObject *object, QMouseEvent *event) {
    if (qobject_cast<QWidget *>(object) &&
        event->button() == Qt::RightButton &&
        userCanAddCurve(QApplication::clipboard()->mimeData())) {
      QMenu contextMenu;

      QAction *pasteAct = new QAction(QIcon::fromTheme("edit-paste"), "Paste",
                                      this);
      contextMenu.addAction(pasteAct);

      QAction *chosenAct = contextMenu.exec(
          qobject_cast<QWidget *>(object)->mapToGlobal(event->pos()));

      if (chosenAct == pasteAct) {
        pasteCurve();
      }
    }
  }