void PlotWindow::autoScaleCheckboxToggled() {
    m_xMinEdit->setEnabled(!m_autoScaleCheckBox->isChecked());
    m_xMaxEdit->setEnabled(!m_autoScaleCheckBox->isChecked());
    m_yMinEdit->setEnabled(!m_autoScaleCheckBox->isChecked());
    m_yMaxEdit->setEnabled(!m_autoScaleCheckBox->isChecked());
  }