void OpenGLWindow::loadGround() {
  m_ground.terminateGL();

  m_ground.loadDiffuseTexture(getAssetsPath() + "maps/cement.jpg");
  m_ground.loadObj(getAssetsPath() + "chamferbox.obj");
  m_ground.setupVAO(m_programs.at(m_currentProgramIndex));
}