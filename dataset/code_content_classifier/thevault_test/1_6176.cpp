int Initialize( int argc, char *argv[]){
  Connect2Port();
  
  //wait until at least one client is connected to output port
  while (outCommandPort.IsReceiving() <= 0){
    YARPTime::DelayInSeconds(1);
  }
return 1;

}