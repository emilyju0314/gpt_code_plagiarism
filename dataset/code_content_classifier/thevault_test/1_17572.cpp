std::string SopasEventMessage::getCommandString() const
{
  std::string commandString;

  switch (m_protocol)
  {
    case CoLa_A:
      commandString = std::string((char *) &m_buffer[2], 2);
      break;
    case CoLa_B:
      commandString = std::string((char *) &m_buffer[9], 2);
  }

  return commandString;
}