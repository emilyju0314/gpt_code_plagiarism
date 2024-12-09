bool SickScanCommon::rebootScanner()
  {
    /*
     * Set Maintenance access mode to allow reboot to be sent
     */
    std::vector<unsigned char> access_reply;


    // changed from "03" to "3"
    int result = convertSendSOPASCommand("\x02sMN SetAccessMode 3 F4724744\x03\0", &access_reply);
    if (result != 0)
    {
      ROS_ERROR("SOPAS - Error setting access mode");
#ifdef USE_DIAGNOSTIC_UPDATER
      if(diagnostics_)
        diagnostics_->broadcast(getDiagnosticErrorCode(), "SOPAS - Error setting access mode.");
#endif
      return false;
    }
    std::string access_reply_str = replyToString(access_reply);
    if (access_reply_str != "sAN SetAccessMode 1")
    {
      ROS_ERROR_STREAM("SOPAS - Error setting access mode, unexpected response : " << access_reply_str);
#ifdef USE_DIAGNOSTIC_UPDATER
      if(diagnostics_)
        diagnostics_->broadcast(getDiagnosticErrorCode(), "SOPAS - Error setting access mode.");
#endif
      return false;
    }

    /*
     * Send reboot command
     */
    std::vector<unsigned char> reboot_reply;
    result = convertSendSOPASCommand("\x02sMN mSCreboot\x03\0", &reboot_reply);
    if (result != 0)
    {
      ROS_ERROR("SOPAS - Error rebooting scanner");
#ifdef USE_DIAGNOSTIC_UPDATER
      if(diagnostics_)
        diagnostics_->broadcast(getDiagnosticErrorCode(), "SOPAS - Error rebooting device.");
#endif
      return false;
    }
    std::string reboot_reply_str = replyToString(reboot_reply);
    if (reboot_reply_str != "sAN mSCreboot")
    {
      ROS_ERROR_STREAM("SOPAS - Error rebooting scanner, unexpected response : " << reboot_reply_str);
#ifdef USE_DIAGNOSTIC_UPDATER
      if(diagnostics_)
        diagnostics_->broadcast(getDiagnosticErrorCode(), "SOPAS - Error setting access mode.");
#endif
      return false;
    }

    ROS_INFO("SOPAS - Rebooted scanner");

    // Wait a few seconds after rebooting
    rosSleep(15.0);

    return true;
  }