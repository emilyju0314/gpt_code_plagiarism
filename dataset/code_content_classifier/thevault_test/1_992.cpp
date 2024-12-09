void UDPPythonClient::startMyself_ () 
{
  //DEPRECATED NOTE/CMNT..BUT GOOD TO REMEMBER
  // MUST go here...DONT take WakeUp interrupts
  // before XMXlateMsg is inited above..UDP Server
  // could already be bdxting to your port w/o
  // the login protocol from a prev failed script
  //
  UDPService::startMyself_();

}