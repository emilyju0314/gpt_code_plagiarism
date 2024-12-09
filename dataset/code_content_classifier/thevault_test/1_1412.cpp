void MainWindow::togglePickStyleNextMode() {
  if (TApp::instance()->getCurrentTool()->getTool()->getName() == T_StylePicker)
    CommandManager::instance()->getAction("A_ToolOption_Mode")->trigger();
  else
    CommandManager::instance()->getAction(T_StylePicker)->trigger();
}