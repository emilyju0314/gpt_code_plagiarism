QList<const QwtPlotSpectrogram *> PlotWindow::plotSpectrograms() const {
    QList<const QwtPlotSpectrogram *> foundSpectrograms;

    const QwtPlotItemList &plotItems = m_plot->itemList();

    for (int itemIndex = 0; itemIndex < plotItems.size(); itemIndex++) {
      const QwtPlotItem *item = plotItems[itemIndex];

      if (item->rtti() == QwtPlotItem::Rtti_PlotSpectrogram) {
        const QwtPlotSpectrogram *spectrogram =
            dynamic_cast<const QwtPlotSpectrogram *>(item);

        if (spectrogram)
          foundSpectrograms.append(spectrogram);
      }
    }

    return foundSpectrograms;
  }