bool Socket::waitForData(size_t timeToWait, size_t timeToCheck)
{
  size_t MaxCount = timeToWait / timeToCheck;
  static size_t count = 0;
  while (bytesWaiting() == 0)
  {
    if (++count < MaxCount)
      ::Sleep(timeToCheck);
    else
      return false;
  }
  return true;
}