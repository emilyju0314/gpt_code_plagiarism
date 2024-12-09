bool ClientHandler::testStringHandling(Socket& socket_)
{
  Show::title("String handling test on server");

  while (true)
  {
    std::string str = socket_.recvString();
    if (socket_ == INVALID_SOCKET)
      return false;
    if (str.size() > 0)
    {
      //Show::write("\n  bytes recvd at server: " + toString(str.size() + 1));
      Show::write("\n  server rcvd : " + str);

      if (socket_.sendString(str))
      {
        Show::write("\n  server sent : " + str);
      }
      else
      {
        return false;
      }
      if (str == "TEST_END")
        break;
    }
    else
    {
      break;
    }
  }
  //socket_.sendString("TEST_STRING_HANDLING_END");
  Show::write("\n  End of string handling test");
  return true;
}