bool sick_scan::SickScanServices::sendSopasAndCheckAnswer(const std::string& sopasCmd, std::vector<unsigned char>& sopasReplyBin, std::string& sopasReplyString)
{
  if(m_common_tcp)
  {
    std::string sopasRequest = std::string("\x02") + sopasCmd + "\x03";
    int result = -1;
    if (m_cola_binary)
    {
      std::vector<unsigned char> reqBinary;
      m_common_tcp->convertAscii2BinaryCmd(sopasRequest.c_str(), &reqBinary);
      result = m_common_tcp->sendSopasAndCheckAnswer(reqBinary, &sopasReplyBin, -1);
    }
    else
    {
      result = m_common_tcp->sendSopasAndCheckAnswer(sopasRequest.c_str(), &sopasReplyBin, -1);
    }
    if (result != 0)
    {
      ROS_ERROR_STREAM("## ERROR SickScanServices::sendSopasAndCheckAnswer: error sending sopas command \"" << sopasCmd << "\"");
    }
    else
    {
      sopasReplyString = m_common_tcp->sopasReplyToString(sopasReplyBin);
      ROS_INFO_STREAM("SickScanServices: Request \"" << sopasCmd << "\" successfully sent, received reply \"" << sopasReplyString << "\"");
      return true;
    }
  }
  else
  {
    ROS_ERROR_STREAM("## ERROR SickScanServices::sendSopasAndCheckAnswer: m_common_tcp not initialized");
  }
  return false;
}