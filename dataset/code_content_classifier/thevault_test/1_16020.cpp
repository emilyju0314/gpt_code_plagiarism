void AutoSlalom::Execute()
{
  if (m_pDrive != nullptr)
  {
    /*
    SwitchColor(DriveTrainSubsystemBase::BROWN);
    loop1();
    loop2();
    loop3();
    SwitchColor(DriveTrainSubsystemBase::BLUE);
    loop4();
    loop5();
    loop6();
    */

    /*
    if (m_loopsUpdate != 0)
    {
      m_state++;
      m_loopsUpdate = 0;
      //m_result = 0;
    }
    */

    //Color 1 is Green
    //Color 2 is Red

    Util::Log("Auto2021 State", m_state);
    m_result = m_pDrive->WhereToTurn(m_center, 25);
    switch (m_state)
    {
    case 0:
      loop0();
      break;
    /*
    case 1:
      m_pDrive->SetLookingColorV(OldCameraVision::GREEN_CONE_N);
      loop1();
      break;
    case 2:
      loop2();
      break;
    case 3:
      loop3();
      break;
    case 4:
      loop4();
      break;
    case 5:
      m_pDrive->SetLookingColorV(OldCameraVision::PURPLE_BOTTLE_N);
      loop5();
      break;
    case 6:
      loop6();
      break;
      */
    default:
      m_pDrive->Stop();
      break;
    }
  }
}