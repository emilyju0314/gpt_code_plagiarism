void BenAutoBounce::Execute() 
{
  switch(m_state)
  {
    case 0:
      ProcessState0();
      break;
    case 1:
      ProcessState1();
      break;
    // case 2:
    //   ProcessState2();
    //   break;
    // case 3:
    //   ProcessState3();
    //   break;
    // case 4:
    //   ProcessState4();
    //   break;
    default:
      m_isFinished = true;
      break;
  }
}