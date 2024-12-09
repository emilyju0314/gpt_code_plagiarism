int_4 UDPSocketLib::UDP_recvFrom (const int_4   sd, 
                                  unsigned char *buf, 
                                  const int_4   bufsize,
                                  const int_u4  flags, 
                                  string        &host,
                                  int_4         &port)
{
  SOCKERR_DECLARE(UDP_recvFrom);
  int status;
  int ngot = 0;
  struct sockaddr_in   clientAddr;
  socklen_t  addrlen = sizeof(clientAddr);
  char client[62];

#if SOLARIS_|SUN_
  status = recvfrom (sd, (char *)buf, 
		     //(char *)bufsize, flags,
		     bufsize, flags,
		     (struct sockaddr *)&clientAddr, &addrlen);
#else
  status = recvfrom (sd, buf, 
		     bufsize, flags,
		     (struct sockaddr *)&clientAddr, &addrlen);
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
      perror("recvfrom...");
      SOCKERR_RECORD("UDP_recvFrom");
      SOCKERR_RETURN(status);
    }

  } else if (status > 0) {
    /* Read some non-zero number of bytes; record their existence
     * and keep going. */
    ngot = status;

    status = UDP_getHostByAddr(client, sizeof(client), &clientAddr);
    string tmpHost (client);
    host = client;
    port = ntohs(clientAddr.sin_port);

  } else {
    /* Probably we reached EOF/no data situation.  Return with whatever 
     * we've got. Prob can't really reach here unless socket is NONBLOCK.*/
    return ngot;
  }

  return ngot;

}