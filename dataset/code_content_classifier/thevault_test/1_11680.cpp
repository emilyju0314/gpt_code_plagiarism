void SocketListener::stop()
{
  stop_.exchange(true);
  sendString("Stop!");
}