cudaError_t cuda::CudaRuntime::cudaMemcpy2DToArray(struct cudaArray *dst, 
	size_t wOffset, size_t hOffset, const void *src, size_t spitch, 
	size_t width, size_t height, enum cudaMemcpyKind kind) {

	_wait();

	cudaError_t result = cudaErrorInvalidValue;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaMemcpy2DtoArray(dst = " << (void *)dst 
		<< ", src = " << (void *)src);
	
	if (kind == cudaMemcpyHostToDevice) {
		executive::Device::MemoryAllocation* destination = 
			_getDevice().getMemoryAllocation(dst);
		
		if (destination == 0) {
			_release();
			_memoryError(dst, width * height, "cudaMemcpy2DtoArray");
		}
		
		size_t dstPitch = _dimensions[destination->pointer()].pitch();

		for (size_t row = 0; row < height; ++row) {
			void* srcPtr = (char*)src + row * spitch;
			size_t dstOffset = (row + hOffset) * dstPitch + wOffset;
			
			if (!_getDevice().checkMemoryAccess((char*)destination->pointer() 
				+ dstOffset, width)) {
				_release();
				_memoryError((char*)destination->pointer() + dstOffset, 
					width, "cudaMemcpy2DtoArray");
			}
			
			destination->copy(dstOffset, srcPtr, width);
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
			_memoryError(dst, width * height, "cudaMemcpy2DtoArray");
		}

		if (source == 0) {
			_release();
			_memoryError(src, width * height, "cudaMemcpy2DtoArray");
		}
		
		size_t dstPitch = _dimensions[destination->pointer()].pitch();
		
		for (size_t row = 0; row < height; ++row) {
			size_t srcOffset = row * spitch;
			size_t dstOffset = (row + hOffset) * dstPitch + wOffset;
			
			if (!_getDevice().checkMemoryAccess((char*)destination->pointer() 
				+ dstOffset, width)) {
				_release();
				_memoryError((char*)destination->pointer() 
					+ dstOffset, width, "cudaMemcpy2DtoArray");
			}

			if (!_getDevice().checkMemoryAccess((char*)source->pointer() 
				+ srcOffset, width)) {
				_release();
				_memoryError((char*)source->pointer() + srcOffset, 
					width, "cudaMemcpy2DtoArray");
			}
			
			source->copy(destination, dstOffset, srcOffset, width);
		}
		
		result = cudaSuccess;
	}
	
	_release();
	return _setLastError(result);
}