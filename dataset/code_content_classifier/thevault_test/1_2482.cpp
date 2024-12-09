std::string GPU_Device::getErrorMessage(cudaError_t const err) {
  auto raw_message = cudaGetErrorString(err);
  std::string message(raw_message);
  return message;
}