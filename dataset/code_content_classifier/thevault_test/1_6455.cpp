void FtpSrvrAgent::recv(Packet*, BayFullTcpAgent* tcp, int code)
{
  if(code == DATA_PUSH) {
    int length = filesize_;
    //tells tcp-full with my mods to send FIN when empty
    tcp->advance(length, 1);
  }
}