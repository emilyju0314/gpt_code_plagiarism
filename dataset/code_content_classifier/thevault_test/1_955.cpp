int_4 UDPSocketLib::UDP_sendTo (const int_4               sd, 
                                const unsigned char                *buf, 
                                const int_4               bufsize,
                                const int_u4              flags, 
                                const struct sockaddr_in* clientAddr, 
                                const int_4               addrlen)
{
  SOCKERR_DECLARE(UDP_sendTo);
  int status;
  int ngot = 0;

#if SOLARIS_|SUN_
  status = sendto (sd, (char *)buf, 
		   //(char *)bufsize, flags);
		   bufsize, flags,
		   (struct sockaddr *)clientAddr, addrlen);
#else
  status = sendto (sd, buf, 
		   bufsize, flags,
		   (struct sockaddr *)clientAddr, addrlen);
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
      perror("UDP_sendTo <clientAddr>...");
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