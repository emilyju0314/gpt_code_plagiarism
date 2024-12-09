void MainWindow::ToggleSkeletonNextMode() {
  if (TApp::instance()->getCurrentTool()->getTool()->getName() == T_Skeleton)
    CommandManager::instance()
        ->getAction("A_ToolOption_SkeletonMode")
        ->trigger();
  else
    CommandManager::instance()->getAction(T_Skeleton)->trigger();
}