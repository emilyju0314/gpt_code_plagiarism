void PlotWindow::showHelp() {
    QDialog *d = new QDialog(m_plot);
    d->setWindowTitle("Basic Help");

    QLabel *zoomLabel = new QLabel("<U>Zoom Options:</U>");
    QLabel *zoomIn = new
                     QLabel("  <b>Left click</b> on the mouse, drag, and release to select an area to zoom in on");
    QLabel *zoomOut = new
                      QLabel("  <b>Middle click</b> on the mouse to zoom out one level");
    QLabel *zoomReset = new
                        QLabel("  <b>Right click</b> on the mouse and select <I>Reset  Scale</I> to clear the zoom and return to the original plot");

    QLabel *curveConfigLabel = new QLabel("<br><U>Curve Configuration:</U>");
    QLabel *configDirections = new
                               QLabel("  <b>To configure the curve properties</b>  Right click on the legend and select <I>Configure</I> from <br>  the menu"
                                      " or click on the configure icon in the tool bar.");
    QLabel *config = new QLabel();
    config->setPixmap(QPixmap(FileName("$ISISROOT/appdata/images/icons/plot_configure.png").expanded()));

    QLabel *tableLabel = new QLabel("<br><U>Table Options:</U>");
    QLabel *tableDirections = new
                              QLabel("  <b>To view the table</b> Click on the File menu and select <I>Show Table</I> or click on the table icon in the <br>   tool bar.");
    QLabel *table = new QLabel();
    table->setPixmap(QPixmap(FileName("$ISISROOT/appdata/images/icons/plot_table.png").expanded()));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(zoomLabel);
    layout->addWidget(zoomIn);
    layout->addWidget(zoomOut);
    layout->addWidget(zoomReset);
    layout->addWidget(curveConfigLabel);
    layout->addWidget(config);
    layout->addWidget(configDirections);
    layout->addWidget(tableLabel);
    layout->addWidget(table);
    layout->addWidget(tableDirections);

    d->setLayout(layout);
    d->show();
  }