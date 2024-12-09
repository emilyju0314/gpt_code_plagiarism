void MainWindow::toggleEraserNextType() {
  if (TApp::instance()->getCurrentTool()->getTool()->getName() == T_Eraser)
    CommandManager::instance()->getAction("A_ToolOption_Type")->trigger();
  else
    CommandManager::instance()->getAction(T_Eraser)->trigger();
}