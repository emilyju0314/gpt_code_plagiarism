void UDPPythonServer::startup_ () 
{
  UDPService::startup_();

  clientArray_.clear();
  loadClientTable_();

  debugMask_  = DebugMask.value();

}