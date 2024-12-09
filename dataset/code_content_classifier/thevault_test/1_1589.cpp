void PlotWindow::fillTable() {
    m_scheduledFillTable = false;

    if (m_tableWindow == NULL) return;
    m_tableWindow->listWidget()->clear();
    m_tableWindow->table()->clear();
    m_tableWindow->table()->setRowCount(0);
    m_tableWindow->table()->setColumnCount(0);

    m_tableWindow->addToTable(true,
                              m_plot->axisTitle(QwtPlot::xBottom).text(),
                              m_plot->axisTitle(QwtPlot::xBottom).text());

    QList<CubePlotCurve *> curves = plotCurves();
    foreach (CubePlotCurve *curve, curves) {
      m_tableWindow->addToTable(true,
                                curve->title().text(),
                                curve->title().text());
    }

    // We really need all of the x-values associated with the curves,
    //   but qwt doesn't seem to want to give this to us. It'll give us the
    //   axis scale, but that isn't quite what we want (especially when zooming)
    //   So let's find the list of x-points ourselves.
    //
    // This is what I tried and it did NOT work:
    // QwtScaleDiv *xAxisScaleDiv = m_plot->axisScaleDiv(QwtPlot::xBottom);
    // QList<double> xAxisPoints = xAxisScaleDiv->ticks(QwtScaleDiv::MajorTick);
    //
    // We're going to keep xAxisPoints in standard text sort order until we're done populating it,
    //   then we'll re-sort numerically. That enables us to effectively use binary searches and
    //   insertion sort-like capabilities for speed.
    QList<QString> xAxisPoints;

    QProgressDialog progress(tr("Re-calculating Table"), tr(""), 0, 1000, this);
    double percentPerCurve = 0.5 * 1.0 / curves.count();

    for (int curveIndex = 0; curveIndex < curves.count(); curveIndex++) {
      progress.setValue(qRound(curveIndex * percentPerCurve * 1000.0));

      CubePlotCurve *curve = curves[curveIndex];

      double percentPerDataIndex = (1.0 / curve->data()->size()) * percentPerCurve;

      // Loop backwards because our insertion sort will have a much better
      //   chance of success on it's first try this way.
      for (int dataIndex = (int)curve->data()->size() - 1;
            dataIndex >= 0;
            dataIndex--) {
        double xValue = curve->data()->sample(dataIndex).x();
        QString xValueString = toString(xValue);

        int inverseDataIndex = (curve->data()->size() - 1) - dataIndex;
        progress.setValue(
            qRound( ((curveIndex * percentPerCurve) +
                     (inverseDataIndex * percentPerDataIndex)) * 1000.0));

        // It turns out that qBinaryFind(container, value) is NOT the same as
        //   qBinaryFind(container.begin(), container.end(), value). Use the one
        //   that works right.
        QList<QString>::const_iterator foundPos =
            qBinaryFind(xAxisPoints.begin(), xAxisPoints.end(), xValueString);

        if (foundPos == xAxisPoints.end()) {
          bool inserted = false;

          for (int searchIndex = 0;
             searchIndex < xAxisPoints.size() && !inserted;
             searchIndex++) {
            if (xAxisPoints[searchIndex] > xValueString) {
              inserted = true;
              xAxisPoints.insert(searchIndex, xValueString);
            }
          }

          if (!inserted)
            xAxisPoints.append(xValueString);
        }
      }
    }

    qSort(xAxisPoints.begin(), xAxisPoints.end(), &numericStringLessThan);

    m_tableWindow->table()->setRowCount(xAxisPoints.size());

    QList<int> lastSuccessfulSamples;

    for (int i = 0; i < curves.count(); i++) {
      lastSuccessfulSamples.append(-1);
    }

    double progressPerRow = 0.5 * 1.0 / m_tableWindow->table()->rowCount();

    for (int row = 0; row < m_tableWindow->table()->rowCount(); row++) {
      progress.setValue(500 + qRound(row * progressPerRow * 1000.0));

      QString xValueString = xAxisPoints[row];
      double xValue = toDouble(xValueString);

      QTableWidgetItem *xAxisItem = new QTableWidgetItem(xValueString);
      m_tableWindow->table()->setItem(row, 0, xAxisItem);

      if (row == m_tableWindow->table()->rowCount() - 1) {
        m_tableWindow->table()->resizeColumnToContents(0);
      }

      // Now search for the x-axis points in the curves to fill in data
      for (int col = 1; col < m_tableWindow->table()->columnCount(); col++) {
        CubePlotCurve *curve = curves[col - 1];

        double y = Null;
        bool tooFar = false;

        for (int dataIndex = lastSuccessfulSamples[col - 1] + 1;
             dataIndex < (int)curve->data()->size() && y == Null && !tooFar;
             dataIndex++) {

          if (toString(curve->data()->sample(dataIndex).x()) == xValueString) {
            // Try to compensate for decreasing x values by not performing this optimization
            if (dataIndex > 0 &&
                curve->data()->sample(dataIndex - 1).x() < curve->data()->sample(dataIndex).x()) {
              lastSuccessfulSamples[col - 1] = dataIndex;
            }
            y = curve->data()->sample(dataIndex).y();
          }
          // Try to compensate for decreasing X values in the too far computation
          else if (dataIndex > 0 &&
              curve->data()->sample(dataIndex - 1).x() < curve->data()->sample(dataIndex).x() &&
              curve->data()->sample(dataIndex).x() > xValue) {
            tooFar = true;
          }
        }

        QTableWidgetItem *item = NULL;

        if (IsSpecial(y))
          item = new QTableWidgetItem(QString("N/A"));
        else
          item = new QTableWidgetItem(toString(y));

        m_tableWindow->table()->setItem(row, col, item);

        if (row == m_tableWindow->table()->rowCount() - 1) {
          m_tableWindow->table()->resizeColumnToContents(col);
        }
      }
    }
  }