bool ClientHandler::testBufferHandling(Socket& socket_)
{
  Show::title("Buffer handling test on server");
  const size_t BufLen = 20;
  Socket::byte buffer[BufLen];
  bool ok;

  while (true)
  {
    ok = socket_.recv(BufLen, buffer);
    if (socket_ == INVALID_SOCKET)
      return false;
    if (ok)
    {
      std::string temp;
      for (size_t i = 0; i < BufLen; ++i)
        temp += buffer[i];
      //Show::write("\n  bytes recvd at server: " + toString(BufLen));
      Show::write("\n  server rcvd : " + temp);

      if (socket_.send(BufLen, buffer))
      {
        Show::write("\n  server sent : " + std::string(buffer));
      }
      else
      {
        Show::write("\n  server send failed");
        return false;
      }
      if (temp.find("TEST_END") != std::string::npos)
        break;
    }
    else
    {
      break;
    }
  }
  Show::write("\n  End of buffer handling test");
  return true;
}