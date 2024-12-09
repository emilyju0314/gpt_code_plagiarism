void MosaicMainWindow::openList() {
    // Set up the list of filters that are default with this dialog.
    QStringList filterList;
    filterList.append("List Files (*.lis)");
    filterList.append("Text Files (*.txt)");
    filterList.append("All files (*)");

    QDir directory = m_lastOpenedFile.dir();

    QString selected = QFileDialog::getOpenFileName(this, "Open Cube List",
        directory.path(), filterList.join(";;"));

    if (selected != "") {
      m_lastOpenedFile = QFileInfo(selected);
      TextFile fileList((QString) selected);

      QStringList filesInList;
      QString line;

      while(fileList.GetLine(line)) {
        filesInList.append(line);
      }

      if (filesInList.empty()) {
        IString msg = "No files were found inside the file list";
        throw IException(IException::Unknown, msg, _FILEINFO_);
      }

      openFiles(filesInList);
    }
  }