int SickScanCommon::stop_scanner(bool force_immediate_shutdown)
  {
    /*
     * Stop streaming measurements
     */
    std::vector<std::string> sopas_stop_scanner_cmd = { "\x02sEN LMDscandata 0\x03\0" };
    if (parser_->getCurrentParamPtr()->getUseEvalFields() == USE_EVAL_FIELD_TIM7XX_LOGIC || parser_->getCurrentParamPtr()->getUseEvalFields() == USE_EVAL_FIELD_LMS5XX_LOGIC)
    {
      sopas_stop_scanner_cmd.push_back("\x02sEN LFErec 0\x03"); // TiM781S: deactivate LFErec messages, send "sEN LFErec 0"
      sopas_stop_scanner_cmd.push_back("\x02sEN LIDoutputstate 0\x03"); // TiM781S: deactivate LIDoutputstate messages, send "sEN LIDoutputstate 0"
      sopas_stop_scanner_cmd.push_back("\x02sEN LIDinputstate 0\x03"); // TiM781S: deactivate LIDinputstate messages, send "sEN LIDinputstate 0"
    }
    sopas_stop_scanner_cmd.push_back("\x02sMN SetAccessMode 3 F4724744\x03\0");
    sopas_stop_scanner_cmd.push_back("\x02sMN LMCstopmeas\x03\0");
    // sopas_stop_scanner_cmd.push_back("\x02sMN Run\x03\0");

    setReadTimeOutInMs(1000);
    ROS_INFO_STREAM("sick_scan_common: stopping scanner ...");
    int result = ExitSuccess, cmd_result = ExitSuccess;
    for(int cmd_idx = 0; cmd_idx < sopas_stop_scanner_cmd.size(); cmd_idx++)
    {
      std::vector<unsigned char> sopas_reply;
      cmd_result = convertSendSOPASCommand(sopas_stop_scanner_cmd[cmd_idx], &sopas_reply, (force_immediate_shutdown==false));
      if (force_immediate_shutdown == false)
      {
        ROS_INFO_STREAM("sick_scan_common: received sopas reply \"" << replyToString(sopas_reply) << "\"");
      }
      if (cmd_result != ExitSuccess)
      {
        ROS_WARN_STREAM("## ERROR sick_scan_common: ERROR sending sopas command \"" << sopas_stop_scanner_cmd[cmd_idx] << "\"");
        result = ExitError;
      }
      // std::this_thread::sleep_for(std::chrono::milliseconds((int64_t)100));
    }
    return result;
  }