QList<const CubePlotCurve *> PlotWindow::plotCurves() const {
    QList<const CubePlotCurve *> foundCurves;

    const QwtPlotItemList &plotItems = m_plot->itemList();

    for (int itemIndex = 0; itemIndex < plotItems.size(); itemIndex++) {
      const QwtPlotItem *item = plotItems[itemIndex];

      if (item->rtti() == QwtPlotItem::Rtti_PlotCurve) {
        const CubePlotCurve *curve = dynamic_cast<const CubePlotCurve *>(item);

        if (curve)
          foundCurves.append(curve);
      }
    }

    return foundCurves;
  }