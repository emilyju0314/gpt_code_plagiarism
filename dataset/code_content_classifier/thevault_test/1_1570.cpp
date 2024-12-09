QList<QwtPlotSpectrogram *> PlotWindow::plotSpectrograms() {
    QList<QwtPlotSpectrogram *> foundSpectrograms;

    const QwtPlotItemList &plotItems = m_plot->itemList();

    for (int itemIndex = 0; itemIndex < plotItems.size(); itemIndex++) {
      QwtPlotItem *item = plotItems[itemIndex];

      if (item->rtti() == QwtPlotItem::Rtti_PlotSpectrogram) {
        QwtPlotSpectrogram *spectrogram =
            dynamic_cast<QwtPlotSpectrogram *>(item);

        if (spectrogram)
          foundSpectrograms.append(spectrogram);
      }
    }

    return foundSpectrograms;
  }