void DataReady::RemoveFD(int n, int events)
{
  int i,j;
  for (i=j=0; i<nfds; i++)
  {
    if (fds[i].fd == n) 
    {
      int e = fds[i].events & ~events;
      if (!e) continue; // if no events left, delete this fd
      fds[i].events = e;
    }
    // move it down in the array if necessary:
    if (j<i)
      { fds[j] = fds[i]; }
    j++;
  }
  nfds = j;
  DataLock();
  /*LOCK*/  if (events & POLLIN)  FD_CLR(n, &_fdsets[0]);
  /*LOCK*/  if (events & POLLOUT) FD_CLR(n, &_fdsets[1]);
  /*LOCK*/  if (events & POLLERR) FD_CLR(n, &_fdsets[2]);
  /*LOCK*/  if (n == _maxfd) _maxfd--;
  DataUnlock();
}