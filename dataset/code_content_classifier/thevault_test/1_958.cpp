int_4 UDPSocketLib::UDP_unblockSocket (int_4 sd)
{
  SOCKERR_DECLARE(UDP_unblockSocket);
  int             status;
  int             blockFlag (NONBLOCK);

  // may need to timeout protect all loops like this...
  //do {
  status = socket_ioctl(sd, FIONBIO, (char *) &blockFlag);
  //} while ((-1 == status) && (EINTR == socket_errno));

  if (status < 0) {
    SOCKERR_RECORD("ioctl(FIONBIO)");
  }
  SOCKERR_RETURN(status);
}