bool IPCServer::WaitReady( unsigned long ulWaitms )
{
  bool bRetVal;

  if( bRetVal = (m_pSemReadyState->WaitAndLock( ulWaitms ) == 0) )
    m_pSemReadyState->ReleaseLock();

  return bRetVal;
}