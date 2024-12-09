void PlotWindow::savePlot() {
    QPixmap pixmap;
    QString output =
    QFileDialog::getSaveFileName((QWidget *)parent(),
                                 "Choose output file",
                                 "./",
                                 QString("Images (*.png *.jpg *.tif)"));
    if (output.isEmpty()) return;
    //Make sure the filename is valid
    if (!output.isEmpty()) {
      if (!output.endsWith(".png") && !output.endsWith(".jpg") && !output.endsWith(".tif")) {
        output = output + ".png";
      }
    }

    QString format = QFileInfo(output).suffix();
    pixmap = m_plot->grab();

    std::string formatString = format.toStdString();
    if (!pixmap.save(output, formatString.c_str())) {
      QMessageBox::information((QWidget *)parent(), "Error", "Unable to save " + output);
      return;
    }
  }