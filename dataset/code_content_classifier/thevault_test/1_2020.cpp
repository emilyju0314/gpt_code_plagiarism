cudaError_t cuda::CudaRuntime::cudaMemcpy2D(void *dst, size_t dpitch, 
	const void *src, size_t spitch, size_t width, size_t height, 
	enum cudaMemcpyKind kind) {

	_wait();

	cudaError_t result = cudaErrorInvalidValue;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaMemcpy2D()");	

	switch (kind) {
		case cudaMemcpyHostToHost:
		{
			for (size_t row = 0; row < height; row++) {
				char* dstPtr = (char*)dst + dpitch * row;
				char* srcPtr = (char*)src + spitch * row;
				std::memcpy(dstPtr, srcPtr, width);
			}
			result = cudaSuccess;
		}
		break;
		case cudaMemcpyDeviceToHost:
		{
			executive::Device::MemoryAllocation* source = 
				_getDevice().getMemoryAllocation(src);
			if (source != 0) {
				for (size_t row = 0; row < height; row++) {
					void* dstPtr = (char *)dst + dpitch * row;
					size_t srcOffset = spitch * row;

					if (!_getDevice().checkMemoryAccess(
						(char*)source->pointer() + srcOffset, width)) {
						_release();
						_memoryError((char*)source->pointer() + srcOffset, 
							width, "cudaMemcpy2D");
					}
					
					source->copy(dstPtr, srcOffset, width);
				}
				result = cudaSuccess;
			}
			else {
				_release();
				_memoryError(src, width * height, "cudaMemcpy2D");
			}
		}
		break;		
		case cudaMemcpyHostToDevice:
		{
			executive::Device::MemoryAllocation* destination = 
				_getDevice().getMemoryAllocation(dst);
			size_t dstPitch = _dimensions[destination->pointer()].pitch();
			if (destination != 0) {
				for (size_t row = 0; row < height; row++) {
					void* srcPtr = (char *)src + spitch * row;
					size_t dstOffset = dstPitch * row;

					if (!_getDevice().checkMemoryAccess(
						(char*)destination->pointer() + dstOffset, width)) {
						_release();
						_memoryError((char*)destination->pointer() + dstOffset, 
							width, "cudaMemcpy2D");
					}
					
					destination->copy(dstOffset, srcPtr, width);
				}
				result = cudaSuccess;
			}
			else {
				_release();
				_memoryError(dst, width * height, "cudaMemcpy2D");
			}
		}
		break;
		case cudaMemcpyDeviceToDevice:
		{
			executive::Device::MemoryAllocation* destination = 
				_getDevice().getMemoryAllocation(dst);
			executive::Device::MemoryAllocation* source = 
				_getDevice().getMemoryAllocation(src);
			if (destination != 0 && source != 0) {
				for (size_t row = 0; row < height; row++) {
					size_t srcOffset = spitch * row;
					size_t dstOffset = dpitch * row;

					if (!_getDevice().checkMemoryAccess(
						(char*)destination->pointer() + dstOffset, width)) {
						_release();
						_memoryError((char*)destination->pointer() + dstOffset, 
							width, "cudaMemcpy2D");
					}
					if (!_getDevice().checkMemoryAccess(
						(char*)source->pointer() + srcOffset, width)) {
						_release();
						_memoryError((char*)source->pointer() + srcOffset, 
							width, "cudaMemcpy2D");
					}
					
					source->copy(destination, dstOffset, srcOffset, width);
				}
				result = cudaSuccess;
			}
			else {
				_release();
				if (destination == 0) {
					_memoryError(dst, width * height, "cudaMemcpy2D");
				}
				else {
					_memoryError(src, width * height, "cudaMemcpy2D");
				}
			}
		}
		break;
		default: break;
	}
	
	_release();
	return _setLastError(result);	
}