int_4 UDPSocketLib::UDP_recv     (const int_4  sd, 
                                  unsigned char         *buf, 
                                  const int_4  bufsize,
                                  const int_u4 flags)
{
  SOCKERR_DECLARE(UDP_recv);
  int status;
  int ngot = 0;

#if SOLARIS_|SUN_
  status = recv (sd, (char *)buf, 
		 //(char *)bufsize, flags);
		 bufsize, flags);
#else
  status = recv (sd, buf, bufsize, flags);
#endif


  if (status < 0) {
    if (EWOULDBLOCK == socket_errno) {
      /* No data available right now, on a non-blocking socket. */
    } else if (EAGAIN == socket_errno) {
      /* No data available right now, on a non-blocking socket. */
    } else if (EINTR == socket_errno) {
      /* Were interrupted while reading, like maybe a condition variable
       * was kicked.  We might consider this a transitory problem, and
       * retry, or we might take this as a cue that we should pop back
       * up to the user and let them see if reality changed.  For now,
       * we'll treat it as transitory... */
    } else {
      /* Some other error.  Notify the caller of the error. */
      ngot = -1;
      perror("recv...");
      SOCKERR_RECORD("UDP_recv");
      SOCKERR_RETURN(status);
    }

  } else if (status > 0) {
    /* Read some non-zero number of bytes; record their existence
     * and keep going. */
    ngot = status;

  } else {
    /* Probably we reached EOF/no data situation.  Return with whatever 
     * we've got. Prob can't really reach here unless socket is NONBLOCK.*/
    return ngot;
  }

  return ngot;

}