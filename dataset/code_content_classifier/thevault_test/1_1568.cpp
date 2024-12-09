QList<CubePlotCurve *> PlotWindow::plotCurves() {
    QList<CubePlotCurve *> foundCurves;

    const QwtPlotItemList &plotItems = m_plot->itemList();

    for (int itemIndex = 0; itemIndex < plotItems.size(); itemIndex++) {
      QwtPlotItem *item = plotItems[itemIndex];

      if (item->rtti() == QwtPlotItem::Rtti_PlotCurve) {
        CubePlotCurve *curve = dynamic_cast<CubePlotCurve *>(item);

        if (curve && curve->color().alpha() != 0)
          foundCurves.append(curve);
      }
    }

    return foundCurves;
  }