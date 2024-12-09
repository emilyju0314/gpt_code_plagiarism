void MainWindow::toggleTapeNextType() {
  if (TApp::instance()->getCurrentTool()->getTool()->getName() == T_Tape)
    CommandManager::instance()->getAction("A_ToolOption_Type")->trigger();
  else
    CommandManager::instance()->getAction(T_Tape)->trigger();
}