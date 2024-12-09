cudaError_t cuda::CudaRuntime::cudaMemcpy2DFromArray(void *dst, size_t dpitch, 
	const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, 
	size_t height, enum cudaMemcpyKind kind) {

	_wait();

	cudaError_t result = cudaErrorInvalidValue;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaMemcpy2DfromArray(dst = " << (void *)dst 
		<< ", src = " << (void *)src);
	
	if (kind == cudaMemcpyDeviceToHost) {
		executive::Device::MemoryAllocation* source = 
			_getDevice().getMemoryAllocation(dst);
		
		if (source == 0) {
			_release();
			_memoryError(src, width * height, "cudaMemcpy2DfromArray");
		}
		
		assert(_dimensions.count(source->pointer()) != 0);
		size_t srcPitch = _dimensions[source->pointer()].pitch();

		for (size_t row = 0; row < height; ++row) {
			void* dstPtr = (char*)dst + row * dpitch;
			size_t srcOffset = (row + hOffset) * srcPitch + wOffset;
			
			if (!_getDevice().checkMemoryAccess((char*)source->pointer() 
				+ srcOffset, width)) {
				_release();
				_memoryError((char*)source->pointer() 
					+ srcOffset, width, "cudaMemcpy2DfromArray");
			}
			
			source->copy(dstPtr, srcOffset, width);
		}
		
		result = cudaSuccess;
	}
	else if (kind == cudaMemcpyDeviceToDevice) {
		executive::Device::MemoryAllocation* destination = 
			_getDevice().getMemoryAllocation(dst);
		executive::Device::MemoryAllocation* source = 
			_getDevice().getMemoryAllocation(src);
		
		if (destination == 0) {
			_release();
			_memoryError(dst, width * height, "cudaMemcpy2DfromArray");
		}

		if (source == 0) {
			_release();
			_memoryError(src, width * height, "cudaMemcpy2DfromArray");
		}
		
		size_t srcPitch = _dimensions[source->pointer()].pitch();
		
		for (size_t row = 0; row < height; ++row) {
			size_t dstOffset = row * dpitch;
			size_t srcOffset = (row + hOffset) * srcPitch + wOffset;
			
			if (!_getDevice().checkMemoryAccess((char*)destination->pointer() 
				+ dstOffset, width)) {
				_release();
				_memoryError((char*)destination->pointer() 
					+ dstOffset, width, "cudaMemcpy2DfromArray");
			}

			if (!_getDevice().checkMemoryAccess((char*)source->pointer() 
				+ srcOffset, width)) {
				_release();
				_memoryError((char*)source->pointer() + srcOffset, width, 
					"cudaMemcpy2DfromArray");
			}
			
			destination->copy(source, srcOffset, dstOffset, width);
		}
		
		result = cudaSuccess;
	}
	
	_release();
	return _setLastError(result);
}