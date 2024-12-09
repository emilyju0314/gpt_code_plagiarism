void SpinWithArm::Execute()
{
  Util::Log("SpinWithArm Selection", m_selector);

  //The spinner can stop at anytime it doesn't need to be at the top
  if (m_selector == UseSpinStop)
  {
    m_pSpinner->SetSpinMotor(0);
    Util::Log("SpinWithArm", 0);
  }

  //------------------------------------------------------

  //Spinner Stuff

  //Checks if we are in the up arm position
  if (m_pArm->GetPosition() == 0)
  {
    //if we are not do not do anything
    return;
  }

  //Checks which function from spin we are using
  switch (m_selector)
  {
  case UseSpinMotor:
    m_pSpinner->SetSpinMotor(m_speed);
    Util::Log("SpinWithArm", 1);
    break;
  case UseSpinToColor:
    m_pSpinner->SpinToColor(m_speed);
    Util::Log("SpinWithArm", 2);
    break;
  case UseSpinWithColor:
    m_pSpinner->SpinNumRotations(m_speed, m_wantedRotation);
    Util::Log("SpinWithArm", 3);
    break;
  default:
    m_pSpinner->Stop();
    Util::Log("SpinWithArm", 4);
    break;
  }

  m_isFinished = true;
}