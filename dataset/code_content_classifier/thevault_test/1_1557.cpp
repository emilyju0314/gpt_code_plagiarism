QAction *SpectralPlotTool::toolPadAction(ToolPad *toolpad) {
    m_toolPadAction = new QAction(toolpad);
    m_toolPadAction->setText("Spectral Plot Tool");
    m_toolPadAction->setIcon(QPixmap(toolIconDir() + "/spectral_plot.png"));
    QString text = "<b>Function:</b> Create a spectral plot using statistics across a spectrum "
                   "(bands).";
    m_toolPadAction->setWhatsThis(text);
    return m_toolPadAction;
  }