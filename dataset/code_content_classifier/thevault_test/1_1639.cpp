void MosaicGridTool::onToolOpen(bool check) {
    if (check && m_shouldCheckBoxes) {
      QSettings settings(
          FileName(QString("$HOME/.Isis/%1/mosaicSceneGridTool.config")
              .arg(QApplication::applicationName())).expanded(),
          QSettings::NativeFormat);

      bool drawAuto = settings.value("autoGrid", true).toBool();
      m_autoGridCheckBox->setChecked(drawAuto);

      // This is necessary to fully initialize properly... the auto increments should still be
      //   the default increments. This will also cause the lat/lon extents to be properly computed.
      if (!drawAuto) {
        autoGrid(true);
        autoGrid(false);
      }

      m_autoGridCheckBox->setEnabled(true);
      m_autoGridLabel->setEnabled(true);
      m_drawGridCheckBox->setChecked(true);
      m_shouldCheckBoxes = false;
    }
  }