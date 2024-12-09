int SickScanCommon::convertSendSOPASCommand(const std::string& sopas_ascii_request, std::vector<unsigned char> *sopas_reply, bool wait_for_reply)
  {
    int result = ExitError;
    if (getProtocolType() == CoLa_B)
    {
      std::vector<unsigned char> requestBinary;
      convertAscii2BinaryCmd(sopas_ascii_request.c_str(), &requestBinary);
      ROS_INFO_STREAM("sick_scan_common: sending sopas command \"" << stripControl(requestBinary) << "\"");
      result = sendSOPASCommand((const char*)requestBinary.data(), sopas_reply, requestBinary.size(), wait_for_reply);
    }
    else
    {
      ROS_INFO_STREAM("sick_scan_common: sending sopas command \"" << sopas_ascii_request << "\"");
      result = sendSOPASCommand(sopas_ascii_request.c_str(), sopas_reply, sopas_ascii_request.size(), wait_for_reply);
    }
    return result;
  }