void MainWindow::TogglePlasticNextMode() {
  if (TApp::instance()->getCurrentTool()->getTool()->getName() == T_Plastic)
    CommandManager::instance()
        ->getAction("A_ToolOption_SkeletonMode")
        ->trigger();
  else
    CommandManager::instance()->getAction(T_Plastic)->trigger();
}