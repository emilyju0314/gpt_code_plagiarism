void PlotWindow::printPlot() {
    QPixmap pixmap;
    /* Initialize a printer*/
    static QPrinter *printer = NULL;
    if (printer == NULL) printer = new QPrinter;
    printer->setPageSize(QPrinter::Letter);
    printer->setColorMode(QPrinter::Color);

    QPrintDialog printDialog(printer, (QWidget *)parent());

    if (printDialog.exec() == QDialog::Accepted) {
      /* Get display widget as a pixmap and convert to an image*/
      pixmap = m_plot->grab();
      QImage img = pixmap.toImage();
      /* C++ Gui Programming with Qt, page 201*/
      QPainter painter(printer);
      QRect rect = painter.viewport();
      QSize size = img.size();
      size.scale(rect.size(), Qt::KeepAspectRatio);
      painter.setViewport(rect.x(), rect.y(),
                          size.width(), size.height());
      painter.setWindow(img.rect());
      painter.drawImage(0, 0, img);
    }

  }