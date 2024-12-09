void UDPSocketLib::UDP_closeSocket (int_4 sd)
{
  SOCKERR_DECLARE(UDP_closeSocket);

  /* TODO(pab:12oct99): Although historically we've ignored any errors that
   * arise on closing a socket, this is a Bad Idea In General.  But since
   * most close(2) failures occur only when writing to disk files, and most
   * people probably won't know what to do in that situation anyway, the
   * only thing we'll do is retry as long as we're getting interrupted by a
   * signal. */

  int rc;
  do {
    rc = socket_close(sd);
  } while ((-1 == rc) && (EINTR == socket_errno));

  return;

}