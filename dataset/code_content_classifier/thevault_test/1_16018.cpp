void Robot::AutonomousInit()
{
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr)
  {
    m_autonomousCommand->Schedule();
  }
}