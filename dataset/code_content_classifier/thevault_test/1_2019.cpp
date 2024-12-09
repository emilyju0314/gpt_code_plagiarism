cudaError_t cuda::CudaRuntime::cudaMallocHost(void **ptr, size_t size) {
	cudaError_t result = cudaErrorMemoryAllocation;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	try {
		executive::Device::MemoryAllocation* 
			allocation = _getDevice().allocateHost(size);
		*ptr = allocation->mappedPointer();
		result = cudaSuccess;
	}
	catch(hydrazine::Exception &exp) {
		report("  cudaMallocHost() - error:\n" << exp.what());
	}

	report("cudaMallocHost( *pPtr = " << (void *)*ptr 
		<< ", size = " << size << ")");
		
	_release();
	return _setLastError(result);
}