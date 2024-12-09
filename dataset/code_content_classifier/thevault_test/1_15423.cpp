void AutoTurn::Execute() {

  constexpr double speed = 0.0;

  PID();
  // Negating the output because wheels are rotating in the wrong direction
  m_driveTrain->ArcadeDrive(speed, -m_output);
}