void GPU_Device::checkForCudaError(cudaError_enum const errorCode) {
  std::ostringstream msg;
  msg << "A CUDA call returned the error: \"" << getErrorMessage(errorCode)
      << "\"";
  Insist(errorCode == CUDA_SUCCESS, msg.str());
}