const char* ep_status_string(EpStatus status) {
  switch(status) {
  case EP_SUCCESS:
    return "Converged";
  case EP_MAX_ITERATIONS_REACHED:
    return "Maximum iterations reached";
  case EP_RESOLUTION_LIMIT_REACHED:
    return "Resolution limit reached";
  case EP_FAILED_TO_CONVERGE:
    return "Failed to converge";
  case EP_NO_PROGRESS:
    return "No progress made";
  case EP_FAILURE:
    return "Unspecified failure";
  case EP_INPUT_ERROR:
    return "Input error";
  default:
    return "Unknown convergence status";
  }
}