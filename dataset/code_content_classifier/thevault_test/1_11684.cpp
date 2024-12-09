void clientTestBufferHandling(Socket& si)
{
  std::string command = "TEST_BUFFER_HANDLING";
  si.sendString(command);
  Show::write("\n  client sent : " + command);

  const int BufLen = 20;
  Socket::byte buffer[BufLen];

  for (size_t i = 0; i < 5; ++i)
  {
    std::string text = "Hello World " + std::string("#") + Conv<size_t>::toString(i + 1);
    for (size_t i = 0; i < BufLen; ++i)
    {
      if (i < text.size())
        buffer[i] = text[i];
      else
        buffer[i] = '.';
    }
    buffer[BufLen - 1] = '\0';
    si.send(BufLen, buffer);
    Show::write("\n  client sent : " + std::string(buffer));
  }
  std::string text = "TEST_END";
  for (size_t i = 0; i < BufLen; ++i)
  {
    if (i < text.size())
      buffer[i] = text[i];
    else
      buffer[i] = '.';
  }
  buffer[BufLen - 1] = '\0';
  si.send(BufLen, buffer);
  Show::write("\n  client sent : " + std::string(buffer));

  bool ok;
  while (true)
  {
    ok = si.recv(BufLen, buffer);
    if (!ok)
    {
      Show::write("\n  client unable to receive");
      break;
    }
    std::string str(buffer);
    if (str.size() == 0)
    {
      Show::write("\n  client detected closed connection");
      break;
    }
    Show::write("\n  client rcvd : " + str);
    if (str.find("TEST_END") != std::string::npos)
    {
      Show::write("\n  End of buffer handling test");
      break;
    }
  }
}