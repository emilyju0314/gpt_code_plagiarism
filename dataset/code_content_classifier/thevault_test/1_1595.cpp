QPair<double, double> PlotWindow::findDataRange(int axisId) const {
    QList<const CubePlotCurve *> curves = plotCurves();

    bool foundDataValue = false;
    QPair<double, double> rangeMinMax;

    foreach(const CubePlotCurve *curve, curves) {
      for (int dataIndex = 0; dataIndex < (int)curve->dataSize(); dataIndex++) {
        if (axisId == QwtPlot::xBottom) {
          if (!foundDataValue) {
            rangeMinMax.first = curve->sample(dataIndex).x();
            rangeMinMax.second = curve->sample(dataIndex).x();
            foundDataValue = true;
          }
          else {
            rangeMinMax.first = qMin(rangeMinMax.first, curve->sample(dataIndex).x());
            rangeMinMax.second = qMax(rangeMinMax.second, curve->sample(dataIndex).x());
          }
        }
        else if (axisId == QwtPlot::yLeft) {
          if (!foundDataValue) {
            rangeMinMax.first = curve->sample(dataIndex).y();
            rangeMinMax.second = curve->sample(dataIndex).y();
            foundDataValue = true;
          }
          else {
            rangeMinMax.first = qMin(rangeMinMax.first, curve->sample(dataIndex).y());
            rangeMinMax.second = qMax(rangeMinMax.second, curve->sample(dataIndex).y());
          }
        }
      }
    }

    if (!foundDataValue) {
      rangeMinMax.first = 1;
      rangeMinMax.second = 10;
    }
    else if(rangeMinMax.first == rangeMinMax.second) {
      rangeMinMax.first -= 0.5;
      rangeMinMax.second += 0.5;
    }

    return rangeMinMax;
  }