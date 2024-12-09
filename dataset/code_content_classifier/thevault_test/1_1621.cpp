void MosaicMainWindow::saveProject() {
    if (m_filename == "") {
      saveProjectAs();
    }
    else {
      m_mosaicController->saveProject(m_filename);
    }
  }