void MosaicMainWindow::open() {
    QStringList filterList;
    filterList.append("Isis cubes (*.cub)");
    filterList.append("All Files (*)");

    QDir directory = m_lastOpenedFile.dir();
    QStringList selected = QFileDialog::getOpenFileNames(this, "Open Cubes",
        directory.path(), filterList.join(";;"));

    if (!selected.empty()) {
      m_lastOpenedFile = QFileInfo(selected.last());
      openFiles(selected);
    }
  }