bool sick_scan::SickScanServices::serviceCbECRChangeArr(sick_scan_srv::ECRChangeArrSrv::Request &service_request, sick_scan_srv::ECRChangeArrSrv::Response &service_response)
{
  std::string sopasCmd = std::string("sEN ECRChangeArr ") + (service_request.active ? "1" : "0");
  std::vector<unsigned char> sopasReplyBin;
  std::string sopasReplyString;

  service_response.success = false;
  if(!sendSopasAndCheckAnswer(sopasCmd, sopasReplyBin, sopasReplyString))
  {
    ROS_ERROR_STREAM("## ERROR SickScanServices::sendSopasAndCheckAnswer failed on sending command\"" << sopasCmd << "\"");
    return false;
  }
  service_response.success = true;

  ROS_INFO_STREAM("SickScanServices: request: \"" << sopasCmd << "\"");
  ROS_INFO_STREAM("SickScanServices: response: \"" << sopasReplyString << "\"");
  
  return true;
}