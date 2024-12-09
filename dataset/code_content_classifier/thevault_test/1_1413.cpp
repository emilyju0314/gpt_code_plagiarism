void MainWindow::toggleRGBPickerNextType() {
  if (TApp::instance()->getCurrentTool()->getTool()->getName() == T_RGBPicker)
    CommandManager::instance()->getAction("A_ToolOption_Type")->trigger();
  else
    CommandManager::instance()->getAction(T_RGBPicker)->trigger();
}