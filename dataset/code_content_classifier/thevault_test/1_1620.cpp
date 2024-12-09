void MosaicMainWindow::saveProjectAs() {
    if (m_mosaicController) {
      QString fn =  QFileDialog::getSaveFileName(this, "Save Project",
                    QDir::currentPath() + "/untitled.mos",
                    "Mosaic (*.mos)");
      if (fn.isEmpty()) return;

      m_mosaicController->saveProject(fn);
      m_filename = fn;
    }
  }