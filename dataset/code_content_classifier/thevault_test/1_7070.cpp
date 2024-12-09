bool FanControl::dbgGetFanControlParamsFromParamsFile(uint8_t fc_idx) {
  /* Create vector to hold hdd temperature words */
  std::vector<std::string> tokens;
  uint16_t max, min;

  /* TODO - Use protobuf to parse the fan control parameters. */

  /* Get the search platform keyword in the table file: GFMS100_SOC,
   * GFMS100_HDD...
   */
  std::string buf = platform_->PlatformName();
  switch (fc_idx) {
    case BRUNO_SOC:
      buf += "_SOC";
      break;
    case BRUNO_IS_HDD:
      buf += "_HDD";
      break;
    case BRUNO_AUX1:
      buf += "_AUX1";
      break;
    default:
      buf += "_UNKNOWN";
      LOG(LS_WARNING) << "Invalid fc_index: " << fc_idx << std::endl;
      break;
  }

  LOG(LS_INFO) << buf << std::endl;

  std::string result = platform_->GetLine((char *)FAN_CONTROL_PARAMS_FILE, &buf);
  if (result.empty() == true)
    return false;

  /* Insert the fan control parameters string into a stream */
  std::stringstream ss(result);
  while (ss >> buf) {
    tokens.push_back(buf);
  }

  /* LOG(LS_INFO) << "token.size = " << tokens.size() << std::endl; */

  /* Each line in the fan control table must have 7 elements */
  if (tokens.size() < 7) {
    LOG(LS_ERROR) << __func__ << "Incorrect number of params -->" << tokens.size() ;
    return false;       /* Incorrect length. Exit. */
  }

  /* Compare Tsetpt and Tmax */
  std::istringstream(tokens.at(1)) >> min;
  std::istringstream(tokens.at(2)) >> max;
  if (min > max) {
    LOG(LS_ERROR) << __func__ << "Incorrect Tsettp: " << min << " and Tmax: " << max;
    return false;   /* Invalid. Exit */
  }

  std::istringstream(tokens.at(4)) >> min;
  std::istringstream(tokens.at(5)) >> max;
  if (min > max) {
    LOG(LS_ERROR) << __func__ << "Dmin: " << min << " and Dmax: " << max;
    return false;   /* Invalid. Exit */
  }

  std::istringstream(tokens.at(1)) >> pfan_ctrl_params_[fc_idx].temp_setpt;
  std::istringstream(tokens.at(2)) >> pfan_ctrl_params_[fc_idx].temp_max;
  std::istringstream(tokens.at(3)) >> pfan_ctrl_params_[fc_idx].temp_step;
  std::istringstream(tokens.at(4)) >> pfan_ctrl_params_[fc_idx].duty_cycle_min;
  std::istringstream(tokens.at(5)) >> pfan_ctrl_params_[fc_idx].duty_cycle_max;
  std::istringstream(tokens.at(6)) >> pfan_ctrl_params_[fc_idx].pwm_step;
  return true;
}