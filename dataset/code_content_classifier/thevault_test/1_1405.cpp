void MainWindow::toggleEditNextMode() {
  if (TApp::instance()->getCurrentTool()->getTool()->getName() == T_Edit)
    CommandManager::instance()
        ->getAction("A_ToolOption_EditToolActiveAxis")
        ->trigger();
  else
    CommandManager::instance()->getAction(T_Edit)->trigger();
}