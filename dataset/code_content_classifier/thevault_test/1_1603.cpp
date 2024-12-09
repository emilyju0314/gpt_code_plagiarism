void WarningWidget::resetWarning(void) {
    if(mbWarningFlag == true) {
      mWarning->setVisible(false);
      mNoWarning->setVisible(true);
      mDialog->setVisible(false);
      mbWarningFlag = false;
      mSBar->showMessage("Ready");
      mMsgStr = "Ready";
    }
  }