int SickScanCommon::init(rosNodePtr nh)
  {
    m_nh = nh;
    int result = init_device();
    if (result != 0)
    {
      ROS_FATAL_STREAM("Failed to init device: " << result);
      return result;
    }

    result = init_scanner(nh);
    if (result != 0)
    {
      ROS_INFO_STREAM("Failed to init scanner Error Code: " << result << "\nWaiting for timeout...\n"
               "If the communication mode set in the scanner memory is different from that used by the driver, the scanner's communication mode is changed.\n"
               "This requires a restart of the TCP-IP connection, which can extend the start time by up to 30 seconds. There are two ways to prevent this:\n"
               "1. [Recommended] Set the communication mode with the SOPAS ET software to binary and save this setting in the scanner's EEPROM.\n"
               "2. Use the parameter \"use_binary_protocol\" to overwrite the default settings of the driver.");
    }

    return result;
  }