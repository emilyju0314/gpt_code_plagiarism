void GPU_Device::checkForCudaError(cudaError_t const errorCode) {
  std::ostringstream msg;
  msg << "A CUDA call returned the error: \"" << getErrorMessage(errorCode) << "\"";
  Insist(errorCode == cudaSuccess, msg.str());
}