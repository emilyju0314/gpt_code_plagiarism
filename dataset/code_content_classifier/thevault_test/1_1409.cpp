void MainWindow::toggleFillNextType() {
  if (TApp::instance()->getCurrentTool()->getTool()->getName() == T_Fill)
    CommandManager::instance()->getAction("A_ToolOption_Type")->trigger();
  else
    CommandManager::instance()->getAction(T_Fill)->trigger();
}