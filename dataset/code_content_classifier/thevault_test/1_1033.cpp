std::string BRErrorAsString(const BrInitError& err) {
    std::string errMsg;
    switch (err) {
    case BR_INIT_ERROR_NOMEM:
      errMsg = "Unable to open /proc/self/maps";
      break;
    case BR_INIT_ERROR_OPEN_MAPS:
      errMsg =  "Unable to read from /proc/self/maps";
      break;
    case BR_INIT_ERROR_READ_MAPS:
      errMsg = "The file format of /proc/self/maps";
      break;
    case BR_INIT_ERROR_INVALID_MAPS:
      errMsg = "The file format of /proc/self/maps is invalid";
      break;
    case BR_INIT_ERROR_DISABLED:
      errMsg = "Binary relocation disabled";
      break;
    default:
      errMsg = "Unknown BrInitError";
    }
    return errMsg;
  }