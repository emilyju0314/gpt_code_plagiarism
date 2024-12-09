cudaError_t cuda::CudaRuntime::_setLastError(cudaError_t result) {
	HostThreadContext& thread = _getCurrentThread();
	thread.lastError = result;
	return result;
}