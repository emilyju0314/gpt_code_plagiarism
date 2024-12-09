bool IsStreamableHMILevel(mobile_apis::HMILevel::eType val) {
  using namespace helpers;
  return Compare<mobile_apis::HMILevel::eType, EQ, ONE>(
      val, mobile_apis::HMILevel::HMI_FULL, mobile_apis::HMILevel::HMI_LIMITED);
}