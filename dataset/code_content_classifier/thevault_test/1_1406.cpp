void MainWindow::toggleSelectionNextType() {
  if (TApp::instance()->getCurrentTool()->getTool()->getName() == T_Selection)
    CommandManager::instance()->getAction("A_ToolOption_Type")->trigger();
  else
    CommandManager::instance()->getAction(T_Selection)->trigger();
}