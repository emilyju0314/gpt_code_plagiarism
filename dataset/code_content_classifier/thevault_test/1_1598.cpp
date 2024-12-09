void PlotWindow::dropEvent(QDropEvent *event) {
    if (m_allowUserToAddCurves &&
        event->mimeData()->hasFormat("application/isis3-plot-curve")) {
      Qt::DropActions possibleActions = event->possibleActions();
      Qt::DropAction actionToTake = event->proposedAction();

      QFont boldFont;
      boldFont.setBold(true);
      QMenu dropActionsMenu;

      QAction *copyAct = new QAction("&Copy Here", this);
      if (possibleActions.testFlag(Qt::CopyAction)) {
        dropActionsMenu.addAction(copyAct);

        if (actionToTake == Qt::CopyAction)
          copyAct->setFont(boldFont);
      }

      QAction *moveAct = new QAction("&Move Here", this);
      if (possibleActions.testFlag(Qt::MoveAction)) {
        dropActionsMenu.addAction(moveAct);

        if (actionToTake == Qt::MoveAction)
          moveAct->setFont(boldFont);
      }

      if (dropActionsMenu.actions().size() > 1) {
        dropActionsMenu.addSeparator();

        QAction *cancelAct = new QAction("&Cancel", this);
        dropActionsMenu.addAction(cancelAct);

        QAction *chosenAct = dropActionsMenu.exec(mapToGlobal(event->pos()));

        if (chosenAct == copyAct) {
          actionToTake = Qt::CopyAction;
        }
        else if (chosenAct == moveAct) {
          actionToTake = Qt::MoveAction;
        }
        else {
          actionToTake = Qt::IgnoreAction;
        }
      }

      if (actionToTake != Qt::IgnoreAction) {
        CubePlotCurve * newCurve = new CubePlotCurve(
                event->mimeData()->data("application/isis3-plot-curve"));
        // add curve to plot
        add(newCurve);
        emit plotChanged();

        event->setDropAction(actionToTake);
        event->accept();
      }
    }
  }