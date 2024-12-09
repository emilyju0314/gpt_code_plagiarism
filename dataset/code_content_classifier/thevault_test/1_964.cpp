string UDPService::ThisHostName ()
{
  char hostname[1024];
  if (gethostname(hostname, 1024) < 0) {
    perror("gethostname");
    return string();
  } else
    return string(hostname);
}