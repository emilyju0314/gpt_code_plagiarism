int_4 UDPSocketLib::UDP_sendTo (const int_4   sd, 
                                const unsigned char    *buf, 
                                const int_4   bufsize,
                                const int_u4  flags, 
                                const string  destHost,
                                const int_4   destPort)
{
  SOCKERR_DECLARE(UDP_sendTo);
  char                hname[MAX_HOSTNAME_LENGTH];
  struct sockaddr_in  destAddr;
  int                 addrlen = sizeof(destAddr);
  int                 status;
  int                 ngot    = 0;

  status = UDP_findHostByName(destHost.c_str(), 
			      hname, 
			      sizeof(hname), 
			      &destAddr);
  if (status < 0) {
    perror("UDP_sendTo:UDP_findHostByName()...");
    SOCKERR_RECORD("Failed <UDP_findHostByName> call;");
    SOCKERR_RETURN(status);
  }

  destAddr.sin_port = htons((u_short) destPort);

#if SOLARIS_|SUN_
  status = sendto (sd, (char *)buf, 
		   //(char *)bufsize, flags);
		   bufsize, flags,
		   (struct sockaddr *)&destAddr, addrlen);
#else
  status = sendto (sd, buf, 
		   bufsize, flags,
		   (struct sockaddr *)&destAddr, addrlen);
#endif

  if (status < 0) {
    if (EWOULDBLOCK == socket_errno) {
      /* No space avail to write data to UDP buffer on a non-blocking socket. */
      ngot = 0;
    } else if (EAGAIN == socket_errno) {
      /* No space avail to write data to UDP buffer on a non-blocking socket. */
      ngot = 0;
    } else if (EINTR == socket_errno) {
      /* Interrupt signal recvd while writing, before data was xmitted.
       * We might consider this a transitory problem, and retry,
       * or we might take this as a cue that we should pop back
       * up to the user and let them see if reality changed.  For now,
       * we'll treat it as transitory... */
      ngot = 0;
    } else {
      /* Some other error.  Notify the caller of the error. */
      perror("UDP_sendTo <destHost:destPort>...");
      SOCKERR_RECORD("Failed <sendto> call;");
      SOCKERR_RETURN(status);
    }

  } else if (status > 0) {
    /* Read some non-zero number of bytes; record their existence
     * and keep going (lets blow this joint...). */
    ngot = status;

  } else {
    /* Probably we reached EOF.  Return with whatever we've got. 
     * A very unlikely place to end up as "sendto" does not return a 0
     * unless of course you sent it a zero (0).  */
    return ngot;
  }

  return ngot;

}