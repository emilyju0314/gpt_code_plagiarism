bool isImageAcquisitionEnabled(ros::NodeHandle &n, std::string dev_ns)
{
  const char NS[] = SERVER_NODE "/";
  std::string ns = NS + dev_ns + "/get_image_acquisition_status";
  ros::ServiceClient client = n.serviceClient<
    omronsentech_camera::GetImageAcquisitionStatus>(ns);
	omronsentech_camera::GetImageAcquisitionStatus srv;
	if (client.call(srv)) 
  {
    return srv.response.value;
  }
  getLastError(n, dev_ns);
  return false;
}