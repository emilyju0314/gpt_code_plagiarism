SocketSystem::~SocketSystem()
{
  int error = WSACleanup();
  Show::write("\n  Socket System cleaning up");
}