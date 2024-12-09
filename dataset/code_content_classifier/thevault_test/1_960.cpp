int_4 UDPSocketLib::UDP_findHostByName (const char *hostname,
      char *h_name_p,
      int_4 h_name_l,
      struct sockaddr_in* sap)
{
  struct hostent * hp;
  
  /* For those of you using purify, gethostbyname seems to use up a 
   * socket on solaris (probably to talk to the dns server).  This
   * is not a problem. */
  hp = gethostbyname(hostname);

  if (0 == hp) {
    return -1;
  }

  if (0 != h_name_p) {
    strncpy(h_name_p, hp->h_name, h_name_l);
    h_name_p[h_name_l-1] = 0;	/* Force EOS termination */
  }
  if (0 != sap) {
    sap->sin_family = hp->h_addrtype;
    memcpy(&sap->sin_addr, hp->h_addr_list[0], hp->h_length);
  }

  return 0;
}