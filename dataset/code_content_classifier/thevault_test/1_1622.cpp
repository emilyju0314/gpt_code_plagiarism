void MosaicMainWindow::loadProject() {
    QString fn =  QFileDialog::getOpenFileName(this, "Load Project",
                  QDir::currentPath(),
                  "Mosaic (*.mos)");

    if (!fn.isEmpty()) {
      closeMosaic();

      m_lastOpenedFile = QFileInfo(fn);
      loadProject(fn);
    }
  }