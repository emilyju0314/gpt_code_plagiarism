void MainWindow::toggleTypeNextStyle() {
  if (TApp::instance()->getCurrentTool()->getTool()->getName() == T_Type)
    CommandManager::instance()->getAction("A_ToolOption_TypeStyle")->trigger();
  else
    CommandManager::instance()->getAction(T_Type)->trigger();
}