void clientTestStringHandling(Socket& si)
{
  std::string command = "TEST_STRING_HANDLING";
  si.sendString(command);
  Show::write("\n  client sent : " + command);

  for (size_t i = 0; i < 5; ++i)
  {
    std::string text = "Hello World " + std::string("#") + Conv<size_t>::toString(i + 1);
    si.sendString(text);
    Show::write("\n  client sent : " + text);
  }
  command = "TEST_END";
  si.sendString(command);
  Show::write("\n  client sent : " + command);

  while (true)
  {
    std::string str = si.recvString();
    if (str.size() == 0)
    {
      Show::write("\n  client detected closed connection");
      break;
    }
    Show::write("\n  client recvd: " + str);
    if (str == "TEST_END")
    {
      Show::write("\n  End of string handling test");
      break;
    }
  }
}