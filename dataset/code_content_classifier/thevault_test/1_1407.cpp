void MainWindow::toggleGeometricNextShape() {
  if (TApp::instance()->getCurrentTool()->getTool()->getName() == T_Geometric)
    CommandManager::instance()
        ->getAction("A_ToolOption_GeometricShape")
        ->trigger();
  else
    CommandManager::instance()->getAction(T_Geometric)->trigger();
}