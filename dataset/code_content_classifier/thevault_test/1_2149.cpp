static void *
heartbeatthread(void *x)
{
  config *r = (config *) x;
  r->heartbeater();
  return 0;
}