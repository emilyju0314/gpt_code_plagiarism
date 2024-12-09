void FtpClientAgent::recv(Packet*, BayFullTcpAgent*, int code)
{
  //at data complete time, schedule a "far out" event to ensure
  // simulator doesn't terminate
  if(running_ && code == DATA_PUSH) {
  state_ = DATA_RCVD;
  newfile_timer_.resched(5.0);
  }
  else if(running_ && code == CONNECTION_END) {
    state_ = END_RCVD;
    newfile_timer_.cancel();
    newfile_timer_.resched(.0);
  }
}