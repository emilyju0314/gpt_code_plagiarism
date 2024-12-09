void WarningWidget::viewWarningWidgetIcon(std:: string &pStr,  const std::string   &pExStr) {
    mbWarningFlag = true;
    mWarning->setVisible(true);
    mNoWarning->setVisible(false);
    std::string sStr = "**PROGRAMMER ERROR** " + pStr;
    mMsgStr = sStr.c_str();
    setWarningText(sStr + "<br>" + pExStr);
  }