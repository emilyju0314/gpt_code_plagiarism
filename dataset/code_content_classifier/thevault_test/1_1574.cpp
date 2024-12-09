void PlotWindow::clearPlotCurves() {
    const QwtPlotItemList &plotItems = m_plot->itemList();

    for (int itemIndex = plotItems.size()- 1; itemIndex >= 0; itemIndex --) {
      QwtPlotItem *item = plotItems[itemIndex];

      if (item->rtti() == QwtPlotItem::Rtti_PlotCurve ||
          item->rtti() == QwtPlotItem::Rtti_PlotHistogram) {
        delete item;
      }
    }

    replot();
  }