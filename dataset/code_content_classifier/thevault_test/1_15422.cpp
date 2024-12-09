void AutoTurn::Initialize() {
  m_driveTrain->ResetGyro();
  // Read the target angle from the dashboard
  m_setpoint = m_driveTrain->m_nte_c_DriveTurnAngle.GetDouble(0.0);
  // Read PID control parameters from the dashboard
  m_kP = m_nte_AutoTurn_kP.GetDouble(1.0);
  m_kI = m_nte_AutoTurn_kI.GetDouble(0.0);
  m_kD = m_nte_AutoTurn_kD.GetDouble(0.0);
}