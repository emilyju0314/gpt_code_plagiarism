std::string GPU_Device::getErrorMessage(cudaError_enum const err) {
  std::string message;
  switch (err) {
  case CUDA_SUCCESS:
    message = std::string("No errors.");
    break;
  case CUDA_ERROR_INVALID_VALUE:
    message = std::string("Invalid value.");
    break;
  case CUDA_ERROR_OUT_OF_MEMORY:
    message = std::string("Out of memory.");
    break;
  case CUDA_ERROR_NOT_INITIALIZED:
    message = std::string("Driver not initialized.");
    break;
  case CUDA_ERROR_DEINITIALIZED:
    message = std::string("Driver deinitialized.");
    break;
  case CUDA_ERROR_NO_DEVICE:
    message = std::string("No CUDA-capable device available.");
    break;
  case CUDA_ERROR_INVALID_DEVICE:
    message = std::string("Invalid device.");
    break;
  case CUDA_ERROR_INVALID_IMAGE:
    message = std::string("Invalid kernel image.");
    break;
  case CUDA_ERROR_INVALID_CONTEXT:
    message = std::string("Invalid context.");
    break;
  case CUDA_ERROR_CONTEXT_ALREADY_CURRENT:
    message = std::string("Context already current.");
    break;
  case CUDA_ERROR_MAP_FAILED:
    message = std::string("Map failed.");
    break;
  case CUDA_ERROR_UNMAP_FAILED:
    message = std::string("Unmap failed.");
    break;
  case CUDA_ERROR_ARRAY_IS_MAPPED:
    message = std::string("Array is mapped.");
    break;
  case CUDA_ERROR_ALREADY_MAPPED:
    message = std::string("Already mapped.");
    break;
  case CUDA_ERROR_NO_BINARY_FOR_GPU:
    message = std::string("No binary for GPU.");
    break;
  case CUDA_ERROR_ALREADY_ACQUIRED:
    message = std::string("Already acquired.");
    break;
  case CUDA_ERROR_NOT_MAPPED:
    message = std::string("Not mapped.");
    break;
  case CUDA_ERROR_INVALID_SOURCE:
    message = std::string("Invalid source.");
    break;
  case CUDA_ERROR_FILE_NOT_FOUND:
    message = std::string("File not found.");
    break;
  case CUDA_ERROR_INVALID_HANDLE:
    message = std::string("Invalid handle.");
    break;
  case CUDA_ERROR_NOT_FOUND:
    message = std::string("Not found.");
    break;
  case CUDA_ERROR_NOT_READY:
    message = std::string("CUDA not ready.");
    break;
  case CUDA_ERROR_LAUNCH_FAILED:
    message = std::string("Launch failed.");
    break;
  case CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES:
    message = std::string("Launch exceeded resources.");
    break;
  case CUDA_ERROR_LAUNCH_TIMEOUT:
    message = std::string("Launch exceeded timeout.");
    break;
  case CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING:
    message = std::string("Launch with incompatible texturing.");
    break;
  case CUDA_ERROR_UNKNOWN:
    message = std::string("Unknown error. ");
    break;
  default:
    // CUDA_ERROR_PROFILER_DISABLED
    // CUDA_ERROR_PROFILER_NOT_INITIALIZED
    // CUDA_ERROR_PROFILER_ALREADY_STARTED
    // CUDA_ERROR_PROFILER_ALREADY_STOPPED
    // CUDA_ERROR_NOT_MAPPED_AS_ARRAY
    // CUDA_ERROR_NOT_MAPPED_AS_POINTER
    // CUDA_ERROR_ECC_UNCORRECTABLE
    // CUDA_ERROR_UNSUPPORTED_LIMIT
    // CUDA_ERROR_CONTEXT_ALREADY_IN_USE
    // CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND
    // CUDA_ERROR_SHARED_OBJECT_INIT_FAILED
    // CUDA_ERROR_OPERATING_SYSTEM
    // CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED
    // CUDA_ERROR_PEER_ACCESS_NOT_ENABLED
    // CUDA_ERROR_PEER_MEMORY_ALREADY_REGISTERED
    // CUDA_ERROR_PEER_MEMORY_NOT_REGISTERED
    // CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE
    // CUDA_ERROR_CONTEXT_IS_DESTROYED
    message = std::string("Unknown error. ");
    break;
  }
  return message;
}