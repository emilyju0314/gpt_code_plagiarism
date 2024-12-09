bool ConvertStringToFloat(const std::string& value_str, float *value) {
  std::stringstream ss(value_str);

  if((ss >> *value).fail()) {
    *value = 0.0;
    LOG(LS_ERROR) << "ConvertStringToFloat: Failed to convert" << std::endl;
    return false;
  }
  return true;
}