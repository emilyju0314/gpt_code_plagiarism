void WarningWidget::checkMessage(void) {
    if(mbWarningFlag == true && mMsgStr.length()) {
      if(mSBar->currentMessage() != mMsgStr)
        mSBar->showMessage(mMsgStr);
    }
  }