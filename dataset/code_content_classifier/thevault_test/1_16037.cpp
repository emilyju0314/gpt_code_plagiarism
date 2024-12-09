void MoveToDistanceCommand::Execute()
{
  double lowTolerance = m_targetDistance - m_toleranceValue;
  double highTolerance = m_targetDistance + m_toleranceValue;
  double currentDistance = m_pDrive->GetLidarDetectionDistance();
  while (currentDistance < lowTolerance || currentDistance > highTolerance)
  {
    if (currentDistance < lowTolerance)
    {
      m_pDrive->MoveTank(-1.0, -1.0);
    }
    else if (currentDistance > highTolerance)
    {
      m_pDrive->MoveTank(1.0, 1.0);
    }
    currentDistance = m_pDrive->GetLidarDetectionDistance();
  }

  m_pDrive->Stop();
  m_isFinished = true;
}