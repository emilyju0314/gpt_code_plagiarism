void OpenGLWindow::loadBunny() {
  m_bunny.terminateGL();

  m_bunny.loadDiffuseTexture(getAssetsPath() + "maps/bunny.jpg");
  m_bunny.loadObj(getAssetsPath() + "bunny.obj");
  m_bunny.setupVAO(m_programs.at(m_currentProgramIndex));
  m_trianglesOfBunny = m_bunny.getNumTriangles();
}